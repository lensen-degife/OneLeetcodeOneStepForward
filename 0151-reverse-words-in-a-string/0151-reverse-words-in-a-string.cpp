class Solution {
public:
    string reverseWords(string s) {

        string word = "";
        stack<string> w;

        for (char c: s){
            if(c != ' '){
                word += c;
            } else if(!word.empty()){
                w.push(word);
                word = "";
            }
        } 
        if(!word.empty()){
            w.push(word);
        }
        string reverse = "";
        while(!w.empty()){
            reverse += w.top();
            w.pop();
            if(!w.empty()){
                reverse += " ";
            }
        }
      
        return reverse;
    }
};