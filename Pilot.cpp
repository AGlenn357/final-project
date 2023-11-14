/*
DiPerna, Glenn, Tyagi
AERSP 424
Final Project
Pilot .cpp File


#include "Pilot.h"
#include <map> //including map library

using namespace std;

Pilot::Pilot(string x) {
				name = x; //setting name value
				stats.insert(make_pair("Maverick", map<int, int>()));
				stats["Maverick"].insert(make_pair(8, map<int, int>());
				stats["Maverick"][8].insert(5, 7);
				
				stats.insert(make_pair("Iceman", map<int, int>()));
				stats["Iceman"].insert(make_pair(6, map<int, int>());
				stats["Iceman"][6].insert(6, 6);
																											
				stats.insert(make_pair("Rooster", map<int, int>()));
				stats["Rooster"].insert(make_pair(4, map<int, int>());
				stats["Rooster"][4].insert(6, 7);
				
				stats.insert(make_pair("Hangman", map<int, int>()));
				stats["Hangman"].insert(make_pair(4, map<int, int>());
				stats["Hangman"][4].insert(8, 5);
				
				experience = stats[name];
				accuracy = stats[name][experience];
				handling = stats[name][experience][accuracy];
				
																												
																												
																								
}
*/
