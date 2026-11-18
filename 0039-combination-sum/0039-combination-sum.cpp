class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(result, candidates, current, target, 0);
        return result;   
    }
    void backtrack( vector<vector<int>> &result,vector<int>& candidates, vector<int>& current, int remaining, int start){
        if(remaining ==0){
            result.push_back(current);
            return;
        }
        for(int i= start; i<candidates.size(); i++){
            if(candidates[i] > remaining){
                break;
            }

            current.push_back(candidates[i]);
            backtrack(result, candidates,current, remaining-candidates[i], i);
            current.pop_back();
        }
    }
};