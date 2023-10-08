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

int daysStayed (const string&  checkIn, const string& checkOut)
{
    tm checkIn1 = {}, checkOut1 = {};
    strptime(checkIn.c_str(), "%Y-%m-%d", &checkIn1);
    strptime(checkOut.c_str(), "%Y-%m-%d", &checkOut1);

    double day1 = difftime(mktime(&checkOut1), mktime(&checkIn1));
    int daystayed = (int)(day1) / 86400;
    
    return daystayed;
}

vector<string> generateDateRange(const string& startDate, const string& endDate) {
    vector<string> dateList;

    tm start_tm = {}, end_tm = {};
    strptime(startDate.c_str(), "%Y-%m-%d", &start_tm);
    strptime(endDate.c_str(), "%Y-%m-%d", &end_tm);

    time_t start_time = mktime(&start_tm);
    time_t end_time = mktime(&end_tm);

    while (start_time <= end_time) {
        tm* current_tm = localtime(&start_time);

        char dateBuffer[11];
        strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", current_tm);

        dateList.push_back(dateBuffer);

        start_time += 86400; 
    }

    return dateList;
}
