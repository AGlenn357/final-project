#include <iostream>
#include <chrono> // library for time calcs.
#include <ctime> // library for date & time
#include <string>

void date_time() 
{
    auto currentTime = std::chrono::system_clock::now(); // retrieves time in UTC
    std::time_t estTime = std::chrono::system_clock::to_time_t(currentTime - std::chrono::hours(5)); // convert time to EST
    std::tm* estTimeStruct = std::localtime(&estTime);

    const std::string month_names[] = {"January", "February", "March", "April", "May", "June",
                                      "July", "August", "September", "October", "November", "December"}; // create an array to store names of months
 
    int year = estTimeStruct->tm_year + 1900; 
    int month = estTimeStruct->tm_mon;       
    int day = estTimeStruct->tm_mday;         
    int hour = estTimeStruct->tm_hour;        
    int min = estTimeStruct->tm_min;          
    int sec = estTimeStruct->tm_sec;       

    // print statement
    std::cout << "You are playing on " << month_names[month] << " " << day << ", " << year << " at " << hour << ":" << min << ":" << sec <<".\nAre you ready to begin? \n"<< std::endl;
}

