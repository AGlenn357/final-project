/*
DiPerna, Glenn, Tyagi
AERSP 424
Final Project
Main File
 */


#include <iostream>
#include <string>
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
                  << "Communication: " << communication << "/5, "
                  << "Reflexes: " << reflexes << "/5" << std::endl;
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
    void startGame(Pilot& pilot, CoPilot& coPilot, Plane& plane) {
        std::cout << "Game started with:" << std::endl;
        pilot.choosePilot();
        if (plane.requiresCoPilot) {
            coPilot.chooseCoPilot();
        }
        plane.choosePlane();
        // Add racing logic here
    }
};

int main() {

    read_logo();

    //Pilot p1("Maverick");
    //cout << p1.getname() << " " <<p1.getaccuracy() << " " << p1.gethandling() << " " << p1.getexperience() << endl;
    
    // Creating an instance of the game
    //RacingGame racingGame;

    // Starting the game with selected pilot, co-pilot, and plane
    //racingGame.startGame(pilots[0], coPilots[0], planes[0]);

    return 0;
}
