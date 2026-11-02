class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m < n) return "";

        unordered_map<char, int> letters;
        for (int i = 0; i < n; i++) {
            letters[t[i]]++;
        }

        int left = 0;
        int minLen = INT_MAX; 
        int startIdx = 0;    
        int count = 0;      

        for (int right = 0; right < m; right++) {

            if (letters[s[right]] > 0) {
                count++;
            }
            letters[s[right]]--;

             while (count == n) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                letters[s[left]]++;
                if (letters[s[left]] > 0) {
                    count--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};