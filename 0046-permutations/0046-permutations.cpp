class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> current;
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);

        backtrack(nums, current, result, used);

        return result;
    }
    void backtrack(vector<int>& nums, vector<int>& current,
                   vector<vector<int>>& result, vector<bool>& used) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i])
                continue;
            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, current,  result, used);

            current.pop_back();
            used[i] = false;
        }
    }
};