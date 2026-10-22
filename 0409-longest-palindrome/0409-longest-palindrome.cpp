class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> unmatched;
        int pairs =0;
        for(char c: s){
            if(unmatched.count(c)){
                pairs++;
                unmatched.erase(c);
            } else{
                unmatched.insert(c);
            }
        }
        int length = pairs *2;
        if(!unmatched.empty()){
            length += 1;
        }
        return length;
    }
};