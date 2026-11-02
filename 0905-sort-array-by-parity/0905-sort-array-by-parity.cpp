class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      
        int right = nums.size() - 1;
        int left = 0;

        while (right > left) {
            if (nums[left] % 2 == 0) {
                left++;
            } 
            else if (nums[right] % 2 == 1) {
                right--;
            } else {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return nums;
    }
};