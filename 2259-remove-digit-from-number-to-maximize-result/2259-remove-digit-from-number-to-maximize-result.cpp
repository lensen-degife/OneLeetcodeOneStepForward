class Solution {
public:
    string removeDigit(string number, char digit) {
        int removeIndex = -1;
        for(int i=0; i < number.length(); i++){
            if(number[i] == digit){
                removeIndex = i;
                if (i + 1 < number.length() && number[i + 1] > number[i]) {
                    break;
                }
            }
         
        }
        return number.substr(0, removeIndex) + number.substr(removeIndex + 1);
    }
};