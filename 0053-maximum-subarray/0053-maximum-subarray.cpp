class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int smax = nums[0];
        int sum = 0;
        for(int right = 0; right < nums.size(); right++){
            
            sum += nums[right];

            smax = max(smax, sum);
            if(sum < 0){
               sum = 0;
            }
        }
        return smax;
    }
};