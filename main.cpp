/*
DiPerna, Glenn, Tyagi
AERSP 424
Final Project
Main File
 */

#include "Final_Project.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <vector>
#include "Pilot.h"
#include "logo.h"

class CoPilot {
public:
    std::string name;
    int experience;
    int communication;
    int reflexes;

    CoPilot(const std::string& n, int exp, int comm, int refl)
        : name(n), experience(exp), communication(comm), reflexes(refl) {}

    void chooseCoPilot() {
        std::cout << "Selected Co-Pilot: " << name << std::endl;
        std::cout << "Experience: " << experience << "/10, "
            << "Communication: " << communication << "/10, "
            << "Reflexes: " << reflexes << "/10" << std::endl;
    }
};

class Plane {
public:
    std::string model;
    int maxSpeed;
    bool requiresCoPilot;
    int maneuverability;

    Plane(const std::string& m, int speed, bool requiresCp, int maneuver)
        : model(m), maxSpeed(speed), requiresCoPilot(requiresCp), maneuverability(maneuver) {}

    void choosePlane() {
        std::cout << "Selected Plane: " << model << std::endl;
        std::cout << "Max Speed: " << maxSpeed << " mph, "
            << "Requires Co-Pilot: " << (requiresCoPilot ? "Yes" : "No") << ", "
            << "Maneuverability: " << maneuverability << "/5" << std::endl;
    }
};

class RacingGame {
public:
    void startGame(Pilot& pilot, CoPilot& 
        coPilot, Plane& plane) {
        std::cout << "Game started with:" << std::endl;
        pilot.choosePilot();
        if (plane.requiresCoPilot) {
            coPilot.chooseCoPilot();
        }
        plane.choosePlane();
        // Add racing logic here
    }
};

int main(int argc, char* argv[]) {

    read_logo();

        std::string chosenPilotName;

        while (true) {
            // Let the player choose their pilot
            std::cout << "\nEnter the name of your pilot (Maverick, Iceman, Rooster, Hangman): ";
            std::cin >> chosenPilotName;

            // Convert the first letter of the entered name to uppercase
            if (!chosenPilotName.empty()) {
                chosenPilotName[0] = std::toupper(chosenPilotName[0]);
            }

            // Check if the entered name is one of the valid options
            if (chosenPilotName == "Maverick" || chosenPilotName == "Iceman" || chosenPilotName == "Rooster" || chosenPilotName == "Hangman") {
                break; // Valid input, exit the loop
            }
            else {
                std::cout << "Invalid pilot name. Please choose from Maverick, Iceman, Rooster, or Hangman.\n";
            }
        }

        // Create a Pilot object with the valid pilot name
        Pilot playerPilot(chosenPilotName);

        // Use the chosen pilot
        playerPilot.choosePilot();

        return 0;
    }

