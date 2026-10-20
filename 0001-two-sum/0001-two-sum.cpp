class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i=0; i < nums.size(); i++){
            int use = nums[i];
            for(int j = i + 1 ; j < nums.size(); j++){
                if(use + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};