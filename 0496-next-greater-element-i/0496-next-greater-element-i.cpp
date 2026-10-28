class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int x : nums1) {
            int j = 0;
            while (j < nums2.size() && nums2[j] != x) ++j;

            int greater = -1;
            for (int k = j + 1; k < nums2.size(); ++k) {
                if (nums2[k] > x) {
                    greater = nums2[k];
                    break;
                }
            }
            ans.push_back(greater);
        }
        return ans;
    }
};