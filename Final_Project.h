// Final_Project.h :

#ifndef FINAL_PROJECT_H
#define FINAL_PROJECT_H

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib> 
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <chrono>

#include "Pilot.h"
#include "Copilot.h"
#include "Plane.h"
#include "logo.h"

class Target {
private:
    double xPos;
    double yPos;
    double radius;
    bool hit;

public:
    Target(double x, double y, double r);

    double getX() const;
    double getY() const;
    double getRadius() const;
    bool isHit() const;

    // Additional methods as needed
    void setHit(bool hit);
    bool isOutOfBounds() const;

    // Function to check if a projectile is within a certain distance of the target
    bool isProjectileNear(double projectileX, double projectileY, double distance) const;
};


class Projectile {
private:
    double xPos;
    double yPos;
    double speed;

public:
    Projectile(double x, double y, double s);

    double getX() const;
    double getY() const;
    double getSpeed() const;

    // Set the vertical position
    void setY(double newY);
};

#endif  // FINAL_PROJECT_H
