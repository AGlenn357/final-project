/*
DiPerna, Glenn, Tyagi
AERSP 424
Final Project
Logo Header File
*/

#pragma once //start of header file
#include <iostream> //including input output library
#include <fstream>

using namespace std; //using standard library

void read_logo()   // main logo displayed at game's start
{
  ifstream txt ("logo.txt", ifstream::in); // read from .txt file
  char c = txt.get();

  while (txt.good()) {
    cout << c;
    c = txt.get();
  }

  txt.close(); // close .txt file

  cout<<"\n"<<endl; // new line 

}
