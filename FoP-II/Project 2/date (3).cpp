#include "main.h"

bool isPastOf(const string &checkIn, const string &checkOut)
{
    if (checkOut <= checkIn)
    {
        return false;
    }
    return true;
}

bool isFuture(const string &checkIn)
{
    time_t currentTime = time(nullptr);
    tm *currentDate = localtime(&currentTime);
    char today[11];
    strftime(today, 11, "%Y-%m-%d", currentDate);

    if (strcmp(checkIn.c_str(), today) < 0)
    {
        return false;
    }
    return true;
}

int daysStayed(const string &checkIn, const string &checkOut)
{
    tm start_tm = {};
    tm end_tm = {};

    istringstream(checkIn) >> get_time(&start_tm, "%Y-%m-%d");
    istringstream(checkOut) >> get_time(&end_tm, "%Y-%m-%d");

    time_t start_time = mktime(&start_tm);
    time_t end_time = mktime(&end_tm);

    return (int)(difftime(end_time, start_time) / (60 * 60 * 24));
}

vector<string> generateDateRange(const string &startDate, const string &endDate)
{
    vector<string> dateRange;

    tm start_tm = {};
    istringstream(startDate) >> get_time(&start_tm, "%Y-%m-%d");

    tm end_tm = {};
    istringstream(endDate) >> get_time(&end_tm, "%Y-%m-%d");

    time_t start_time = mktime(&start_tm);
    time_t end_time = mktime(&end_tm);

    const int day_seconds = 60 * 60 * 24;

    for (time_t current_time = start_time; current_time <= end_time; current_time += day_seconds)
    {
        tm current_tm = *localtime(&current_time);
        char date_buffer[11];
        strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d", &current_tm);
        dateRange.push_back(date_buffer);
    }

    return dateRange;
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const string &date)
{
    if (date.length() != 10)
    {
        return false;
    }
    istringstream iss(date);
    int year, month, day;
    char dash1, dash2;
    if (iss >> year >> dash1 >> month >> dash2 >> day && dash1 == '-' && dash2 == '-')
    {
        if (year >= 0 && month >= 1 && month <= 12 && day >= 1)
        {
            int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if (isLeapYear(year))
            {
                daysInMonth[2] = 29;
            }

            if (day <= daysInMonth[month])
            {
                return true;
            }
        }
    }
    return false;
}
