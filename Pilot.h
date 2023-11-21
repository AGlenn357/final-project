/*
DiPerna, Glenn, Tyagi
AERSP 424
Final Project
Pilot Header File
*/

#pragma once //start of header file
#include <iostream>
#include <string>
#include <map>

class Pilot {
private:
    std::string name;
    int experience;
    int accuracy;
    int handling;
    static std::map<std::string, std::tuple<int, int, int>> stats;

public:
    Pilot(const std::string& n);

    std::string getname();
    int getexperience();
    int getaccuracy();
    int gethandling();
    void choosePilot();
};

