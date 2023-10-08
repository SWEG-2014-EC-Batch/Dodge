#include "main.h"

bool isPastOf (const string& checkIn, const string& checkOut)
{
    if (checkOut <= checkIn)
    {
        return false;
    }
    return true;
}

bool isFuture (const string& checkIn)
{
    time_t currentTime = time(nullptr);
    tm* currentDate = localtime(&currentTime);
    char today[11];
    strftime(today, 11, "%Y-%m-%d", currentDate);

    if (strcmp(checkIn.c_str(), today) < 0)
    {
        return false;
    }
    return true;
}

int daysStayed(const std::string& checkIn, const std::string& checkOut) { 
    std::tm start_tm = {}; 
    std::tm end_tm = {}; 
     
    // Parse the date strings into std::tm structures 
    std::istringstream(checkIn) >> std::get_time(&start_tm, "%Y-%m-%d"); 
    std::istringstream(checkOut) >> std::get_time(&end_tm, "%Y-%m-%d"); 
 
    // Convert the std::tm structures to time_t 
    std::time_t start_time = std::mktime(&start_tm); 
    std::time_t end_time = std::mktime(&end_tm); 
 
    // Calculate the difference in days 
    return static_cast<int>(std::difftime(end_time, start_time) / (60 * 60 * 24)); 
}

std::vector<std::string> generateDateRange(const std::string& startDate, const std::string& endDate) { 
    std::vector<std::string> dateRange; 
 
    // Parse the start date string into a std::tm structure 
    std::tm start_tm = {}; 
    std::istringstream(startDate) >> std::get_time(&start_tm, "%Y-%m-%d"); 
 
    // Parse the end date string into a std::tm structure 
    std::tm end_tm = {}; 
    std::istringstream(endDate) >> std::get_time(&end_tm, "%Y-%m-%d"); 
 
    // Convert the std::tm structures to time_t 
    std::time_t start_time = std::mktime(&start_tm); 
    std::time_t end_time = std::mktime(&end_tm); 
 
    // Calculate the number of seconds in a day 
    const int day_seconds = 60 * 60 * 24; 
 
    // Generate the date range 
    for (std::time_t current_time = start_time; current_time <= end_time; current_time += day_seconds) { 
        std::tm current_tm = *std::localtime(&current_time); 
        char date_buffer[11]; // Buffer for date in "YYYY-MM-DD" format 
        std::strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d", &current_tm); 
        dateRange.push_back(date_buffer); 
    } 
 
    return dateRange; 
}
