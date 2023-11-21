#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Racing_Game.h"
#define _USE_MATH_DEFINES
#include <cmath>

class Target {
public:
    int position;

    Target(int pos) : position(pos) {}
};


void RacingGame::simulateRace(Pilot& pilot, CoPilot& coPilot, Plane& plane) {
    // Set the race distance to 30 miles
    int raceDistance = 30;

    // Calculate the number of iterations needed to cover the race distance
    int iterations = (raceDistance * 5280) / forward_plane_speed; // Assuming 1 mile = 5280 units

    // Set the initial position of the plane at the bottom
    int planePosition = 10; // Assuming a 100-unit vertical space, adjust as needed
    int planeHorizontalPosition = 40; // Initial horizontal position

    for (int i = 0; i < iterations; ++i) {
        // Handle player input
        handleInput(pilot, planeHorizontalPosition);

        // Simulate scrolling targets towards the plane at the calculated speed
        for (double targetPosition = 0; targetPosition < planePosition; targetPosition += forward_plane_speed) {
            // Draw the game elements
            clearScreen();
            drawTriangle(planeHorizontalPosition, planePosition);
            drawCircle(targetPosition, 20, 5);

        }

        // Simulate shooting a projectile when the space bar is pressed
        if (isSpacePressed()) {
            std::cout << "Projectile shot!" << std::endl;
            // Draw the projectile
            drawProjectile(planeHorizontalPosition, planePosition);
        }

   
    }
}

void RacingGame::drawTriangle(int x, int y) {
    // Draw a triangle
    std::cout << "  ^  " << std::endl;
    std::cout << " / \\ " << std::endl;
    std::cout << "/___\\" << std::endl;
}

void RacingGame::drawCircle(double x, double y, int radius) {
    // Draw a circle
    for (int i = 0; i <= 360; i += 10) {
        double radians = i * 3.1415926535 / 180.0;
        int circleX = static_cast<int>(x + radius * std::cos(radians));
        int circleY = static_cast<int>(y + radius * std::sin(radians));
        std::cout << "\033[" << circleY << ";" << circleX << "H" << "*";
    }
}

void RacingGame::drawProjectile(int x, int y) {
    // Draw a projectile (star)
    std::cout << "\033[" << y << ";" << x << "H" << "*";
}

void RacingGame::clearScreen() {
    // Clear the console screen
    std::system("clear");
}

void RacingGame::handleInput(Pilot& pilot, int& planeHorizontalPosition) {
    // Handle player input
    // Implement your ASCII-based input handling logic here
}

bool RacingGame::isSpacePressed() {
    // Implement your ASCII-based space bar check here
    return false;
}

void RacingGame::calculateSpeeds(Pilot& pilot, CoPilot& coPilot, Plane& plane) {
    // Calculate left-to-right plane speed based on plane's maneuverability
    l_r_plane_speed = plane.getmaneuverability() * 0.6;

    // Check if the plane has a co-pilot
    if (plane.getRequiresCoPilot()) {
        // Add contributions from co-pilot's reflexes and communication
        l_r_plane_speed = coPilot.getreflexes() * 0.3 + coPilot.getcommunication() * 0.5;
    }

    // Calculate forward plane speed based on plane's max speed, pilot's experience, and handling
    forward_plane_speed = plane.getmaxSpeed() * (5280.0 / 3600.0); // Convert maxSpeed from mph to ft/sec
    forward_plane_speed /= 5000000; // Divide forward_plane_speed by 2500
    forward_plane_speed += 0.8 * pilot.getexperience() + 0.5 * pilot.gethandling(); // Add contributions from pilot's experience and handling

    // Check if the plane has a co-pilot
    if (plane.getRequiresCoPilot()) {
        // Add contributions from co-pilot's experience
        forward_plane_speed += 0.8 * coPilot.getexperience();
    }
}
