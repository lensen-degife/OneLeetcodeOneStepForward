class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        int n = nums.size();
        backtrack(nums, current, used, result, n);
        return result;
    }
    void backtrack(vector<int>& nums, vector<int>& current,
                   vector<bool>& used,
                   vector<vector<int>>& result, int n) {
        int m = current.size();
        if (m == n) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, current, used, result, n);

            current.pop_back();
            used[i] = false;
        }
    }
};