class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> collection;
        string val;
        for (char c: s) {
            if (!collection.empty() && collection.top() == c) {
                collection.pop();
            } else {
                collection.push(c);
            }
        }
        while(!collection.empty()){
            val += collection.top();
            collection.pop();
        }
        reverse(val.begin(), val.end());
        return val;
    }
};