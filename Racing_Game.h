// Racing_Game.h
#pragma once

#include "Pilot.h"
#include "CoPilot.h"
#include "Plane.h"
#include "Logo.h"

class RacingGame {
private:
    double forward_plane_speed; // Speed attribute for the RacingGame in ft/sec
    double l_r_plane_speed;     // Left-to-right plane speed in ft/sec

public:
    // Function to simulate the racing logic with both pilot and copilot
    int simulateRace(Pilot& pilot, CoPilot& coPilot, Plane& plane);

    // Function to handle player input using ASCII
    void handleInput(Pilot& pilot, int& planeHorizontalPosition);

    // Function to check if the space bar is pressed using ASCII
    bool isSpacePressed();

    // Function to calculate left-to-right plane speed and forward plane speed
    void calculateSpeeds(Pilot& pilot, CoPilot& coPilot, Plane& plane);

    // Function to draw a circle using ASCII characters
    void drawCircle(double x, double y, int radius);

    // Function to draw a triangle using ASCII characters
    void drawTriangle(int x, int y);

    // Function to draw a star using ASCII characters
    void drawProjectile(int x, int y);

    void clearScreen();
    
    int drawBoard(double target_x, double target_y, int triangle_x, int accuracy);
    
    std::vector<std::vector<int>> drawTarget(int x, int y);
    
    //void read_logo2();
};
