// Plane.h
#pragma once

#include <iostream>
#include <string>
#include <tuple>

class Plane {
private:
    std::string model;
    int maxSpeed;
    bool requiresCoPilot;
    int maneuverability;

public:
    Plane(const std::string& m);

    std::string getmodel() const;
    int getmaxSpeed() const;
    bool getRequiresCoPilot() const;
    int getmaneuverability() const;

    void choosePlane() const;
};
