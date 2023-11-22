#pragma once

#include <iostream>
#include <string>
#include <tuple>

class CoPilot {
private:
    std::string name;
    int experience;
    int communication;
    int reflexes;

public:
    CoPilot(const std::string& n);

    std::string getname() const;
    int getexperience() const;
    int getcommunication() const;
    int getreflexes() const;

    void chooseCoPilot() const;
};

