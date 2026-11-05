class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric from left
            while (left < right && !isalnum(s[left])) left++;
            // Skip non-alphanumeric from right
            while (left < right && !isalnum(s[right])) right--;
            
            // Compare lowercase versions
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};