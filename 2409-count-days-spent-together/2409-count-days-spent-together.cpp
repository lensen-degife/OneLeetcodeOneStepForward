class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Number of days in each month for a non-leap year
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Helper lambda to convert "MM-DD" to the nth day of the year
        auto dateToDays = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            
            int totalDays = 0;
            // Add days from all preceding full months
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonth[i];
            }
            // Add the days in the current month
            totalDays += day;
            
            return totalDays;
        };
        
        // Convert all dates to day of the year
        int aStart = dateToDays(arriveAlice);
        int aEnd = dateToDays(leaveAlice);
        int bStart = dateToDays(arriveBob);
        int bEnd = dateToDays(leaveBob);
        
        // Calculate the overlap interval
        int startOverlap = max(aStart, bStart);
        int endOverlap = min(aEnd, bEnd);
        
        // If startOverlap > endOverlap, they don't intersect, so return max with 0
        return max(0, endOverlap - startOverlap + 1);
    }
};