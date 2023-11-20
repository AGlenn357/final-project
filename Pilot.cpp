/*
DiPerna, Glenn, Tyagi
AERSP 424
Final Project
Pilot .cpp File
*/

#include "Pilot.h"

std::map<std::string, std::tuple<int, int, int>> Pilot::stats;

Pilot::Pilot(const std::string& x) {
    name = x;

    // Assuming initial values for each pilot
    if (x == "Maverick") {
        std::tie(experience, accuracy, handling) = std::make_tuple(8, 5, 7);

    }
    else if (x == "Iceman") {
        std::tie(experience, accuracy, handling) = std::make_tuple(6, 6, 6);
    }
    else if (x == "Rooster") {
        std::tie(experience, accuracy, handling) = std::make_tuple(4, 6, 7);
    }
    else if (x == "Hangman") {
        std::tie(experience, accuracy, handling) = std::make_tuple(4, 8, 5);
    }
}

std::string Pilot::getname() {
    return name;
}

int Pilot::getexperience() {
    return experience;
}

int Pilot::getaccuracy() {
    return accuracy;
}

int Pilot::gethandling() {
    return handling;
}

void Pilot::choosePilot() {
    std::cout << "Selected Pilot: " << name << std::endl;
    std::cout << "Experience: " << experience << "/10, "
        << "Accuracy: " << accuracy << "/10, "
        << "Handling: " << handling << "/10" << std::endl;
}

