/*
Diperna, Glenn, Tyagi
AERSP 424
Final Project
main.cpp file
*/

#include "Pilot.h" //include Pilot header file
#include "Logo.h" //include Logo header file
#include "Plane.h" //include Plane header file
#include "CoPilot.h" //include CoPilot header file
#include "Racing_Game.h" //include Racing_Game header file
#include <iostream> //include input output library
#include <string> //include string library
#include <vector> //include vector library

// function to convert entries to all lowercase for easy recognition
std::string toLowerCase(const std::string& str) {
    std::string lowerCaseStr = str;
    for (char& c : lowerCaseStr) {
        c = tolower(c);
    }
    return lowerCaseStr;
}

//function to output how the play the game
void directions() {
    std::cout << "HOW TO PLAY" << std::endl << "Use the s and d keys to move the plane left and right.  For precise lateral movement, use the j and k keys.  Use the c key to speed the plane up, and the d key to slow the plane down.  Press enter after input.  Good luck!" << std::endl << std::endl << std::endl;
}

int main() {
    std::system("Clear"); //clear screen
    read_logo(); //display logo

    // Let the player choose their pilot
    int again = 1;
    std::vector <int> scores;
    while (true) {
        std::cout << again << std::endl;
        
        std::string chosenPilotName; //pilot name
        while (true) { //loop to get pilot name
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
        
        Pilot playerPilot(chosenPilotName); //create pilot object based on choosen pilot
        playerPilot.choosePilot(); //output pilot statistics
        
        // Let the player choose their plane
        std::string chosenPlaneModel; //plane
        while (true) { //loop to get plane
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
        
        Plane playerPlane(chosenPlaneModel); //create plane object based on choosen plane
        playerPlane.choosePlane(); //output plane statistics
        
        std::string chosenCoPilotName;
        // Check if the chosen plane requires a co-pilot
        if (playerPlane.getRequiresCoPilot()) {
            // Let the player choose their co-pilot
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
        }
        else {
            // Create a dummy CoPilot instance with all values set to 0
            chosenCoPilotName = "Dummy";
        }
        
        CoPilot playerCoPilot(chosenCoPilotName); //create CoPilot object
        if (chosenCoPilotName != "Dummy") {
            playerCoPilot.chooseCoPilot(); //output CoPilot stats
        }
        
        directions();
        RacingGame racingGame;
        scores.push_back(racingGame.simulateRace(playerPilot, playerCoPilot, playerPlane));
        std::cout << "Personal best time: " << *std::min_element(scores.begin(),scores.end()) << std::endl;
        
        int again;
        std::cout << "Play again? (Enter 0 for no and 1 for yes)" << std::endl;
        std::cin >> again;
        while (again != 0 && again != 1) {
            std::cout << "Invalid input" << std::endl;
            std::cout << "Play again? (Enter 0 for no and 1 for yes)" << std::endl;
            std::cin >> again;
        }
        if (again == 0) {
            break;
        }
    }
    
    return 0;
}
