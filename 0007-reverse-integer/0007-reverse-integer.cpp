class Solution {
public:
    int reverse(int x) {
        long long reverse= 0;
        while(x != 0){
            int lastDigit = x%10;
            reverse = (reverse*10) + lastDigit;
            x = x/10;
            
        }
 
        if(reverse < pow(-2, 31) || reverse > pow(2, 31) -1 ){
            return 0;
         }
        return reverse;
        
    }
};