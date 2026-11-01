class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int count = 0;
        int left = 0;
        unordered_map<int,int> map;
        for(int i =0; i<fruits.size(); i++){
            map[fruits[i]]++;
            while(map.size() > 2){
                map[fruits[left]]--;
                if(map[fruits[left]] == 0){
                    map.erase(fruits[left]);
                }
                left++;
            }
            count = max(count, i -left + 1);
        }
        return count;
    }
};