/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps7a>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <4.21.2022>*/
/*Sources Of Help: Dr. Daly's Discord*/
/*Copyright 2022 <John Hua>*/
/************************************************************/
#include <iostream>
#include <fstream>
#include <string>

#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>


using boost::gregorian::date;
using boost::posix_time::ptime;
using boost::posix_time::time_duration;

int main(int argc, char* argv[]) {
    std::string fileName = argv[1];
    std::ifstream log(argv[1]);
    std::ofstream rpt(fileName + ".rpt", std::ofstream::out);
    std::string line;

    if (argc < 2 || argc > 2) {
        throw std::runtime_error
        ("Correct usage: ./ps7 <log_file_name>");
    }


    time_duration bootTime;

    date startDate;
    date endDate;

    ptime startTime;
    ptime endTime;

    int lineCnt = 1;

    boost::regex startBoot(
    "([0-9]{4})-([0-9]{2})-([0-9]{2}) "
    "([0-9]{2}):([0-9]{2}):([0-9]{2}): "
    "\\(log.c.166\\) "
    "server started.*");

    boost::regex endBoot(
    "([0-9]{4})-([0-9]{2})-([0-9]{2}) "
    "([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3})"
    ":INFO:oejs.AbstractConnector:Started "
    "SelectChannelConnector@0.0.0.0:9080.*");

    bool conseqBoot = false;
    if (log.is_open()) {
        while (getline(log, line)) {
            boost::smatch sm;
            if (boost::regex_match(line, sm, startBoot))  {
                startDate = date(stoi(sm[1]), stoi(sm[2]), stoi(sm[3]));
                startTime = ptime
                (startDate, time_duration
                (stoi(sm[4]), stoi(sm[5]), stoi(sm[6])));

            /*Found consecutive boot line following start boot*/
            if (conseqBoot) {
                rpt << "**** Incomplete Boot ****\n" << std::endl;
                conseqBoot = false;
            }
            std::string dateString = sm[1] + "-" + sm[2] + "-" + sm[3];
            std::string timeString = sm[4] + ":" + sm[5] + ":" + sm[6];
            rpt << "=== Device boot ===\n"
                << lineCnt << "(" << fileName << "): "
                << dateString << " "
                << timeString
                << "    Boot Start" << std::endl;
            conseqBoot = true;

            /*Found successful boot line following start boot*/
            } else if (boost::regex_match(line, sm, endBoot)) {
                endDate = date(stoi(sm[1]), stoi(sm[2]), stoi(sm[3]));
                endTime = ptime
                (endDate, time_duration(stoi(sm[4]), stoi(sm[5]), stoi(sm[6])));
            std::string dateString = sm[1] + "-" + sm[2] + "-" + sm[3];
            std::string timeString = sm[4] + ":" + sm[5] + ":" + sm[6];
            rpt << lineCnt << "(" << fileName << "): "
                << dateString << " "
                << timeString
                << "    Boot Completed" << std::endl;
                bootTime = endTime - startTime;
            rpt << "    Boot Time: "
                << bootTime.total_milliseconds() << "ms\n" << std::endl;
                conseqBoot = false;
            }
            lineCnt++;
        }
        rpt.close();
        log.close();
    }
}
