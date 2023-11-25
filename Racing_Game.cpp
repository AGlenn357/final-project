#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Racing_Game.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <random>

int normal(double mean, double std) {
    std::random_device rd{}; //random device
    std::mt19937 gen{rd()}; //from homework assignment
    std::normal_distribution<> d{mean, std}; //getting normal distribution
    return d(gen); //returning answer
}

int RacingGame::simulateRace(Pilot& pilot, CoPilot& coPilot, Plane& plane) {
    int handling = pilot.gethandling()+0.25*coPilot.getreflexes()+plane.getmaneuverability();
    int accuracy = pilot.getaccuracy()+0.25*coPilot.getcommunication();
    int accuracy_normal = 0.85*accuracy;
    int speed_normal;
    if (plane.getmodel() == "F-14") {
        speed_normal = 3;
    }
    else if (plane.getmodel() == "F-15ex") {
        speed_normal = 4;
    }
    else if (plane.getmodel() == "F-16") {
        speed_normal = 2;
    }
    else if (plane.getmodel() == "F-18") {
        speed_normal = 1;
    }
    else {
        speed_normal = 1;
    }
    
    std::cout << "Full Plane Conditions:"  << std::endl << "handling: " << handling << ", speed: " << speed_normal << ", accuracy: " << accuracy_normal << std::endl;
    
    int target_y = 2;
    int pos = 50;
    int maneuver = handling;
    if (maneuver <= 0) {
        maneuver = 1;
    }

    //int speed2;
    int target_x = -1;
    while (target_x <= 6 || target_x >= 94) {
        target_x = normal(50, 20);
    }
    int n = 0;
    std::string blank;
    std:: cout << "Enter any key for the game to begin." << std::endl;
    std:: cin >> blank;
    std::system("clear");
    auto start1 = std::chrono::steady_clock::now();
    while (n < 5) {
        char s;
        read_logo();
        int nn = drawBoard(target_x, target_y, pos, accuracy_normal);
        if (nn == 1) {
            std::system("clear");
            std::cout<<"Game Over: You crashed."<<std::endl << std::endl << std::endl <<std::endl;
            break;
        }
        std::cout << "time: " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start1).count() << std::endl;
        if (nn == 1) {
            break;
        }
        std::cin>>s;
        if (s == 's') {
            pos = pos - maneuver;
            if (pos < 3) {
                pos = 3;
            }
        }
        else if (s == 'd') {
            pos = pos + maneuver;
            if (pos > 96) {
                pos = 96;
            }
        }
        else if (s == 'e') {
            speed_normal++;
        }
        else if (s == 'c') {
            speed_normal--;
        }
        else if (s == 'j') {
            pos--;
        }
        else if (s == 'k') {
            pos++;
        }
        std::system("Clear");
        target_y = target_y + speed_normal;
        if (target_y > 30 && abs(target_x-pos) <= accuracy-3) {
            target_y = 2;
            target_x = normal(50,35);
            n++;
            while (target_x <= 6 || target_x >= 94) {
                target_x = normal(50, 20);
            }
        }
    }
    if (n == 5) {
        std::cout << "time: " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start1).count() << " seconds" << std::endl;
        return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start1).count();
    }
    else {
        return 10000; //returning insanely high time
    }
}

std::vector <std::vector<int>> RacingGame::drawTarget(int x, int y) {
    std::vector <std::vector<int>> pairs2;
    pairs2.push_back({x-4,x-3, x-2, x-1, x, x+1, x+2, x+3,x+4});
    pairs2.push_back({y-1, y});

    return pairs2;
}

int RacingGame::drawBoard(double target_x, double target_y, int triangle_x, int accuracy) {
    int nn = 0;
    int triangle_y = 28;
    
    for (int i = 0; i <= 100; i++) {
        std:: cout << "_";
    }
    std:: cout << "\n";
    
    std::vector<std::vector<int>> pairs;
    pairs = drawTarget(target_x, target_y);
    
    //checking if the plane is hitting the obstacle
    if (abs(target_x-triangle_x) > accuracy && target_y == 27) {
        nn = 1;
    }
    else if (abs(target_x-triangle_x) > accuracy-2 && target_y == 28) {
        nn = 1;
    }
    else if (abs(target_x-triangle_x) > accuracy-3 && target_y == 29) {
        nn = 1;
    }
    else if (abs(target_x-triangle_x) > accuracy-3 && target_y >= 30) {
        nn = 1;
    }
    else { //if plane is not hitting the obstacle plot results
        for (int i = 0; i < 30; i++) {
            std::cout<<"|";
            for (int j = 0; j < 99; j++) {
                int n = 0;
                for (int k = 0; k < pairs[1].size(); k++) {
                    for (int l = 0; l < pairs[0].size(); l++) {
                        if(pairs[1][k] == i && abs(target_x - j) >= accuracy && n == 0) {
                            std::cout << "#";
                            n = 1;
                        }
                    }
                }
                if (j == triangle_x && i == triangle_y-1) {
                    std::cout<< "^";
                    n = 1;
                }
                else if (j == triangle_x-1 && i == triangle_y) {
                    std::cout << "/";
                    n = 1;
                }
                else if (j == triangle_x+1 && i == triangle_y) {
                    std::cout << "\\";
                    n = 1;
                }
                else if (j == triangle_x-2 && i == triangle_y+1) {
                    std::cout<<"/";
                    n = 1;
                }
                else if (j == triangle_x+2 && i == triangle_y+1) {
                    std::cout<<"\\";
                    n = 1;
                }
                else if (j == triangle_x-1 && i == triangle_y+1) {
                    std::cout<<"_";
                    n = 1;
                }
                else if (j == triangle_x && i == triangle_y+1) {
                    std::cout<<"_";
                    n = 1;
                }
                else if (j == triangle_x+1 && i == triangle_y+1) {
                    std::cout<<"_";
                    n = 1;
                }
                if (n == 0) {
                    std::cout << " ";
                }
            }
            std::cout << "|" << "\n";
        }
    }
    return nn; //return nn, nn is 1 if the plane crashed
}
