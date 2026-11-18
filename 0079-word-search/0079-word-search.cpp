class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int columns = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int row, int column,
             int index) {
        if (index == word.size()) {
            return true;
        }
        if (row >= board.size() || row < 0 || column >= board[0].size() ||
            column < 0 || word[index] != board[row][column]){
            return false;
            }
        char temp = board[row][column];
        board[row][column] = '#';
        bool found = dfs(board, word, row+1, column, index + 1) ||
                     dfs(board, word, row -1, column, index + 1) ||
                     dfs(board, word, row, column+1, index + 1) ||
                     dfs(board, word, row, column - 1, index + 1) ;
        board[row][column] = temp;
        return found;
        
    }
};