class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int i = 0;
        int temp;

        while (i <= right) {
            if (nums[i] == 0) {
                temp = nums[i];
                nums[i] = nums[left];
                nums[left] = temp;
                left++;
                i++;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            }
            else {
                i++;
            }
        }
    }
};