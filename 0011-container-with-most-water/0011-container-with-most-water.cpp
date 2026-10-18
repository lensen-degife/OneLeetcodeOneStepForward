class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() -1;
        int left = 0;
        int maxWater = 0;
        while(right > left){
            int current_width = right - left;
            int current_height = min(height[left], height[right]);
            int current_area = current_width * current_height;

            maxWater= max(maxWater, current_area);
            if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
        }
        return maxWater;
        
    }
};