
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> elements(nums.begin(), nums.end());
        int longest = 0;

        for (int num : elements) {
            if (elements.find(num - 1) == elements.end()) {
                int current = num;
                int count = 1;

                while (elements.find(current + 1) != elements.end()) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
