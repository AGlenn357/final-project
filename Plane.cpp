// Plane.cpp
#include "Plane.h"

Plane::Plane(const std::string& m) {
    model = m;

    // Assuming initial values for each plane
    if (m == "F-14") {
        std::tie(maxSpeed, requiresCoPilot, maneuverability) = std::make_tuple(1544, true, 3);
    }
    else if (m == "F-15ex") {
        std::tie(maxSpeed, requiresCoPilot, maneuverability) = std::make_tuple(1875, true, 2);
    }
    else if (m == "F-16") {
        std::tie(maxSpeed, requiresCoPilot, maneuverability) = std::make_tuple(1500, false, 5);
    }
    else if (m == "F-18") {
        std::tie(maxSpeed, requiresCoPilot, maneuverability) = std::make_tuple(1187, false, 4);
    }
}

std::string Plane::getmodel() const {
    return model;
}

int Plane::getmaxSpeed() const {
    return maxSpeed;
}

bool Plane::getRequiresCoPilot() const {
    return requiresCoPilot;
}

int Plane::getmaneuverability() const {
    return maneuverability;
}

void Plane::choosePlane() const {
    std::cout << "Selected Plane: " << model << std::endl;
    std::cout << "Max Speed: " << maxSpeed << " mph, "
        << "Requires Co-Pilot: " << (requiresCoPilot ? "Yes" : "No") << ", "
        << "Maneuverability: " << maneuverability << "/5" << std::endl;
}
