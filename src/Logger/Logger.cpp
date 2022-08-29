//
// Created by sarah on 8/27/22.
//

#include "Logger.h"
#include <iostream>
#include <ctime>
#include <string>

std::vector<LogEntry> Logger::messages;

char * getDate() {
    time_t curr_time;
    tm * curr_tm;
    time(&curr_time);
    curr_tm = localtime(&curr_time);
    char * realTime = (char *)malloc(100* sizeof(char));
    std::strftime(realTime, 50, "%D %T", curr_tm);
    return realTime;
}


void Logger::Log(const std::string &message) {
    LogEntry newEntry;
    newEntry.type = LOG_INFO;
    auto dateString = getDate();
    newEntry.message = "LOG: [" + std::string(dateString) + "] - " + message;
    std::cout<<"\033[;32m"<< newEntry.message <<std::endl;
    free(dateString);
    messages.push_back(newEntry);
}

void Logger::Err(const std::string &message) {
    LogEntry newEntry;
    newEntry.type = LOG_ERROR;
    auto dateString = getDate();
    newEntry.message = "ERR: [" + std::string(dateString) + "] - " + message;
    std::cout<<"\031[;32m" << newEntry.message <<std::endl;
    free(dateString);
    messages.push_back(newEntry);
}