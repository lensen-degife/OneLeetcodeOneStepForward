class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> sums;

        for (int i = 0; i<nums.size(); i++){
            int missing = target - nums[i];
            if(sums.count(missing)){
                return {sums[missing], i};
            } 
            sums[nums[i]] = i;
        }

            return {};
        }
};