class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;
        int longest = 0;

        for (int num : arr1) {
            string s = to_string(num);
            string prefix = "";

            for (char c : s) {
                prefix += c;
                prefixes.insert(prefix);
            }
        }

        for (int num : arr2) {
            string s = to_string(num);
            string prefix = "";

            for (char c : s) {
                prefix += c;

                if (prefixes.count(prefix)) {
                    longest = max(longest, (int)prefix.size());
                } else {
                    break;
                }
            }
        }

        return longest;
    }
};