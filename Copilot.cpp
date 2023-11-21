// CoPilot.cpp
#include "CoPilot.h"

CoPilot::CoPilot(const std::string& x) {
    name = x;

    // Assuming initial values for each co-pilot
    if (x == "Goose") {
        std::tie(experience, communication, reflexes) = std::make_tuple(7, 8, 7);
    }
    else if (x == "Bob") {
        std::tie(experience, communication, reflexes) = std::make_tuple(4, 6, 9);
    }
}

std::string CoPilot::getname() const {
    return name;
}

int CoPilot::getexperience() const {
    return experience;
}

int CoPilot::getcommunication() const {
    return communication;
}

int CoPilot::getreflexes() const {
    return reflexes;
}

void CoPilot::chooseCoPilot() const {
    std::cout << "Selected Co-Pilot: " << name << std::endl;
    std::cout << "Experience: " << experience << "/10, "
        << "Communication: " << communication << "/10, "
        << "Reflexes: " << reflexes << "/10" << std::endl;
}
