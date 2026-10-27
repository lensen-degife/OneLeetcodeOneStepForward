class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string num = to_string(x);
        int right = num.size()-1;
        int left = 0;
        while(left < right){
            if(num[left] != num[right]) return false;
            left++;
            right--;
    }
     return true;
    }
};