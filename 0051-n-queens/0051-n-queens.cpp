class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);
        vector<bool> mainDiag(2 * n - 1, false);
        vector<bool> antiDiag(2 * n - 1, false);

        dfs(0, n, board, result, cols, mainDiag, antiDiag);
        return result;
    }

private:
    void dfs(int row, int n, vector<string>& board,
             vector<vector<string>>& result,
             vector<bool>& cols, vector<bool>& mainDiag,
             vector<bool>& antiDiag) {
        // Base case: all rows 0..n-1 have a queen
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int mainIdx = row - col + (n - 1);
            int antiIdx = row + col;

            // Prune if column or either diagonal is already attacked
            if (cols[col] || mainDiag[mainIdx] || antiDiag[antiIdx]) {
                continue;
            }

            // Choose
            board[row][col] = 'Q';
            cols[col] = true;
            mainDiag[mainIdx] = true;
            antiDiag[antiIdx] = true;

            // Explore
            dfs(row + 1, n, board, result, cols, mainDiag, antiDiag);

            // Undo (Backtrack)
            board[row][col] = '.';
            cols[col] = false;
            mainDiag[mainIdx] = false;
            antiDiag[antiIdx] = false;
        }
    }
};