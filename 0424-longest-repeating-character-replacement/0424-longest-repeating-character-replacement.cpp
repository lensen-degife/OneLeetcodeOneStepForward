class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> smap;
        int res = 0;
        int left = 0;
        int maxFreq = 0;
        for(int right=0; right<s.length(); right++){
            smap[s[right]]++;
            maxFreq = max(maxFreq, smap[s[right]]);
            while(right-left + 1 - maxFreq> k){
                smap[s[left]]--;
                left++;
            }

            res = max(res, right-left +1);
        }
        return res;

    }
};