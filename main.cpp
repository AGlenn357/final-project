#include "Final_Project.h"
#include "Pilot.h"
#include "logo.h"
#include "date_time.h"
#include "Plane.h"
#include "CoPilot.h"
#include "Racing_Game.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

// function to convert entries to all lowercase for easy recognition
std::string toLowerCase(const std::string& str) {
    std::string lowerCaseStr = str;
    for (char& c : lowerCaseStr) {
        c = tolower(c);
    }
    return lowerCaseStr;
}

int main(int argc, char* argv[]) {
    // Read and display the logo
    read_logo();
    date_time();

    // Let the player choose their pilot
    std::string chosenPilotName;
    while (true) {
        std::cout << "Enter the name of your Pilot: (Maverick, Iceman, Rooster, Hangman) \n Pilot: ";
        std::cin >> chosenPilotName;
        chosenPilotName[0] = toupper(chosenPilotName[0]); // Convert the first letter to uppercase

        // Check if the entered pilot name is valid
        std::string lowerCasePilotName = toLowerCase(chosenPilotName);
        if (lowerCasePilotName == "maverick" || lowerCasePilotName == "iceman" || lowerCasePilotName == "rooster" || lowerCasePilotName == "hangman") {
            break; // Valid input, exit the loop
        }
        else {
            std::cout << "Invalid pilot name. Please choose from Maverick, Iceman, Rooster, or Hangman.\n";
        }
    }
    Pilot playerPilot(chosenPilotName);
    playerPilot.choosePilot();

    // Let the player choose their plane
    std::string chosenPlaneModel;
    while (true) {
        std::cout << "Enter the model of your Plane: (F-14, F-15ex, F-16, F-18) \n Plane Model: ";
        std::cin >> chosenPlaneModel;
        chosenPlaneModel[0] = toupper(chosenPlaneModel[0]); // Convert the first letter to uppercase

        // Check if the entered plane model is valid
        std::string lowerCasePlaneModel = toLowerCase(chosenPlaneModel);
        if (lowerCasePlaneModel == "f-14" || lowerCasePlaneModel == "f-15ex" || lowerCasePlaneModel == "f-16" || lowerCasePlaneModel == "f-18") {
            break; // Valid input, exit the loop
        }
        else {
            std::cout << "Invalid plane model. Please choose from F-14, F-15ex, F-16, or F-18.\n";
        }
    }

    Plane playerPlane(chosenPlaneModel);
    playerPlane.choosePlane();

    // Check if the chosen plane requires a co-pilot
    if (playerPlane.getRequiresCoPilot()) {
        // Let the player choose their co-pilot
        std::string chosenCoPilotName;
        while (true) {
            std::cout << "Enter the name of your Co-Pilot: (Goose, Bob) \n Co-Pilot: ";
            std::cin >> chosenCoPilotName;
            chosenCoPilotName[0] = toupper(chosenCoPilotName[0]); // Convert the first letter to uppercase

            // Check if the entered co-pilot name is valid
            std::string lowerCaseCoPilotName = toLowerCase(chosenCoPilotName);
            if (lowerCaseCoPilotName == "goose" || lowerCaseCoPilotName == "bob") {
                break; // Valid input, exit the loop
            }
            else {
                std::cout << "Invalid co-pilot name. Please choose from Goose or Bob.\n";
            }
        }
        CoPilot playerCoPilot(chosenCoPilotName);
        playerCoPilot.chooseCoPilot();

        // Create an instance of RacingGame and start the game with pilot, plane, and co-pilot
        RacingGame racingGame;
        racingGame.simulateRace(playerPilot, playerCoPilot, playerPlane);
    }
    else {
        // Create a dummy CoPilot instance with all values set to 0
        CoPilot dummyCoPilot("Dummy");
        dummyCoPilot.chooseCoPilot();

        // Create an instance of RacingGame and start the game with pilot and plane
        RacingGame racingGame;
        racingGame.simulateRace(playerPilot, dummyCoPilot, playerPlane);
    }

    return 0;
}



