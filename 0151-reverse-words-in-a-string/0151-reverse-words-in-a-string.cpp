class Solution {
public:
    string reverseWords(string s) {
        int n = s.size() -1;
        string result = "";

        while(n >= 0){
            
            while( n >= 0 && s[n] == ' '){
                n--;
            }
            if(n < 0) break;

            int j = n;
            while(j >=  0 && s[j] != ' '){
                j--;
            }
            string word = s.substr(j+1, n-j);

            if(!result.empty()){
                result += " ";
            }
            result += word;
            n= j;
        }
    return result;
    }
};