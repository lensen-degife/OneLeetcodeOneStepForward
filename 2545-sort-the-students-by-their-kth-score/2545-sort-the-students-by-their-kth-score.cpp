class Solution {
private:
    void merge(vector<vector<int>>& score, int left, int mid, int right, int k) {
        vector<vector<int>> temp;
        temp.reserve(right - left + 1);
        
        int i = left;
        int j = mid + 1;
        
        // Take the row with the larger k-th score first
        while (i <= mid && j <= right) {
            if (score[i][k] >= score[j][k]) {
                temp.push_back(move(score[i++]));
            } else {
                temp.push_back(move(score[j++]));
            }
        }
        
        while (i <= mid) temp.push_back(move(score[i++]));
        while (j <= right) temp.push_back(move(score[j++]));
        
        for (int idx = 0; idx < temp.size(); idx++) {
            score[left + idx] = move(temp[idx]);
        }
    }
    
    void mergeSort(vector<vector<int>>& score, int left, int right, int k) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(score, left, mid, k);
        mergeSort(score, mid + 1, right, k);
        merge(score, left, mid, right, k);
    }

public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        mergeSort(score, 0, score.size() - 1, k);
        return score;
    }
};