class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> days(n, 0);
        stack<int> reading;
        for(int i =0; i< n; i++){
         while (!reading.empty() && temperatures[i] > temperatures[reading.top()]) {
                 int previous = reading.top();
                reading.pop();
                days[previous] = i - previous; 
            }
            reading.push(i);
        }
        return days;
    }
};