// RacingGame.cpp
#include "Racing_Game.h"

void RacingGame::startGame(Pilot& pilot, CoPilot& coPilot, Plane& plane) {
    std::cout << "Game started with:" << std::endl;
    pilot.choosePilot();

    if (plane.getRequiresCoPilot()) {
        coPilot.chooseCoPilot();
    }

    plane.choosePlane();
    // Add racing logic here
}
