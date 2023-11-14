/*
DiPerna, Glenn, Tyagi
AERSP 424
Final Project
Pilot Header File
*/

#pragma once //start of header file
#include <iostream> //including input output library
#include <string> //including string library

using namespace std; //using standard library

class Pilot { //class Pilot
private: //private members
    string name; //name
    int experience; //experience
    int accuracy; //accuracy
    int handling; //handline
public:
    Pilot(); //constructor
    ~Pilot() {}; //deconstructor
    string getname(){ //getting name
        return name; //returning name
    }
    int getexperience() { //getting experience
        return experience; //returning experience
    }
    int getaccuracy() { //getting accuracy
        return accuracy; //returning accuracy
    }
    int gethandling() { //getting handling
        return handling; //returning handling
    }
    void setname(string x) { //setting name
        name = x; //set name
    }
    void setexperience(int x) { //setting experience
        experience = x; //set experience
    }
    void setaccuracy(int x) { //setting accuracy
        accuracy = x; //set accuracy
    }
    void sethandling(int x) { //setting handling
        handling = x; //set handling
    }
    Pilot(const string& n, int exp, int acc, int hand)
        : name(n), experience(exp), accuracy(acc), handling(hand) {}

    void choosePilot() {
        std::cout << "Selected Pilot: " << name << std::endl;
        std::cout << "Experience: " << experience << "/10, "
                  << "Accuracy: " << accuracy << "/5, "
                  << "Handling: " << handling << "/5" << std::endl;
    }
};
