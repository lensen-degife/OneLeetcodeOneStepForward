class Solution {
public:
    string removeDigit(string number, char digit) {
        int removeIndex = -1;
        for(int i=0; i<number.size(); i++){
            if(number[i]== digit){
                removeIndex = i;
                if(number[i] < number[i+1] ){
                    break;
                }
            }

        }
        return number.substr(0,removeIndex) + number.substr(removeIndex + 1);
    }
};