class Solution {
public:
  #include <string>
#include <sstream>
#include <iostream>

int countDaysTogether(std::string arriveAlice, std::string leaveAlice, std::string arriveBob, std::string leaveBob) {
    // Helper function to convert date string to day of the year
    auto dateToDay = [](const std::string& date) {
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));
        // Days in each month for a non-leap year
        int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        
        int dayOfYear = day; // Start with the day of the current month
        for (int i = 0; i < month - 1; ++i) {
            dayOfYear += daysInMonth[i]; // Add days from previous months
        }
        return dayOfYear;
    };
    
    // Convert the arrival and departure dates to day of the year
    int arriveAliceDay = dateToDay(arriveAlice);
    int leaveAliceDay = dateToDay(leaveAlice);
    int arriveBobDay = dateToDay(arriveBob);
    int leaveBobDay = dateToDay(leaveBob);
    
    // Calculate the overlap of days
    int start = std::max(arriveAliceDay, arriveBobDay);
    int end = std::min(leaveAliceDay, leaveBobDay);
    
    // If there is no overlap, return 0
    if (start > end) {
        return 0;
    }
    
    // Return the number of overlapping days
    return end - start + 1; // +1 to include both start and end days
}
};