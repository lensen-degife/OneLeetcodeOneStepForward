class Solution {
public:
    int countDigits(int num) {
        int divisible = 0;
        int original = num;
        while(num != 0){
            int least = num % 10 ;
            if(original % least == 0){
                divisible++;
            }
            num /= 10;
        }
        return divisible;

    }
};