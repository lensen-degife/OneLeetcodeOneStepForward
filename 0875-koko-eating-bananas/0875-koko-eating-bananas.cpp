class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (high > low) {
            int mid = low + (high - low) / 2;
            if (canFinish(piles, mid, h)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

private:
    bool canFinish(const vector<int>& piles, int k, int h) {

        long long hours=0;
        for (int pile : piles) {
            hours += (pile + (long long)k - 1) / k;
            if (hours > h)
                return false;
        }
        return hours <= h;
    }
};