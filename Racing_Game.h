 // RacingGame.h
#pragma once
#include "Pilot.h"
#include "CoPilot.h"
#include "Plane.h"

class RacingGame {
public:
    void startGame(Pilot& pilot, CoPilot& coPilot, Plane& plane);
};

