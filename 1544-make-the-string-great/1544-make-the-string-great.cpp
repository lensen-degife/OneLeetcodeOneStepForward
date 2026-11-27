class Solution {
public:
    string makeGood(string s) {
        
        string good ;

        for(char c: s){
            if(!good.empty()&& abs(good.back() - c) == 32){
                good.pop_back();
            } 
            else{
                good.push_back(c);
            }
        }
        return good;
    }
};