class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        
        // Initialize an empty N x N board filled with dots
        vector<string> board(n, string(n, '.'));
        
        // Arrays to track which columns and diagonals are under attack
        vector<bool> cols(n, false);
        vector<bool> posDiag(2 * n, false);
        vector<bool> negDiag(2 * n, false);
        
        // Start placing queens from row 0
        backtrack(0, n, board, result, cols, posDiag, negDiag);
        
        return result;
    }

private:
    // A helper function to handle the recursive backtracking
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& result, 
                   vector<bool>& cols, vector<bool>& posDiag, vector<bool>& negDiag) {
        
        // Base case: If we successfully reached row 'n', we found a valid board!
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {
            
            // Calculate the unique identifiers for this square's diagonals
            int pDiag = row + col;
            int nDiag = row - col + n; 
            
            // If the column or either diagonal is already under attack, skip to the next column
            if (cols[col] || posDiag[pDiag] || negDiag[nDiag]) {
                continue;
            }
            
            // 1. PLACE THE QUEEN
            board[row][col] = 'Q';
            cols[col] = true;
            posDiag[pDiag] = true;
            negDiag[nDiag] = true;
            
            // 2. MOVE TO THE NEXT ROW
            backtrack(row + 1, n, board, result, cols, posDiag, negDiag);
            
            // 3. BACKTRACK (Undo our placement and try the next spot)
            board[row][col] = '.';
            cols[col] = false;
            posDiag[pDiag] = false;
            negDiag[nDiag] = false;
        }
    }
};