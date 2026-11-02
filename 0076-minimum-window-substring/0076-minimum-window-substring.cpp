class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty() || s.size() < t.size()) return "";

        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int required = need.size();          // how many unique chars we still need
        int formed = 0;                      // how many unique chars are currently satisfied

        unordered_map<char, int> window;
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;                       // start index of the best window

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            window[c]++;

            // If this character is needed and we just reached the required count
            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            // Try to shrink the window from the left as much as possible
            while (left <= right && formed == required) {
                // Update the best answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove the leftmost character
                char leftChar = s[left];
                window[leftChar]--;
                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    formed--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};