// Recursion Backtracing ]
//TC - O(N! * N) SC - O(N^2)
class Solution {
public:
    bool isSafe(int i, int j, int n, vector<string> &board){
        for(int row = 0; row<i; row++){
            if(board[row][j] == 'Q') return false;
        }

        int row = i;
        int col = j;

        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q')    return false;

            row--;
            col--;
        }

        row = i;
        col = j;

        while(row >= 0 && col < n){
            if(board[row][col] == 'Q') return false;

            row--;
            col++;
        }
        return true;
    }

    void solve(int row,const int &n, vector<string> &board, vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++){
            if(isSafe(row, col, n, board)){
                board[row][col] = 'Q';
                solve(row+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i=0;i<n; i++){
            s.push_back('.');
        }
        vector<string> board(n, s);
        vector<vector<string>> ans;
        
        solve(0, n, board, ans);
        return ans;
    }    
};

// Optimal approach
//SC - O(N)
class Solution {
public:
    void solve(int row,const int &n, vector<int> &cols, vector<int> &leftd, vector<int> &rightd, vector<string> &board, vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++){
            if(cols[col] == 0 && leftd[row+col] == 0 && rightd[(n-1) + (col-row)] == 0){
                cols[col] = 1;
                leftd[row+col] = 1;
                rightd[(n-1) + (col-row)] = 1;
                board[row][col] = 'Q';
                solve(row+1, n, cols, leftd, rightd, board, ans);
                board[row][col] = '.';
                cols[col] = 0;
                leftd[row+col] = 0;
                rightd[(n-1) + (col-row)] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        vector<vector<string>> ans;
        
        vector<int> cols(n, 0);
        vector<int> leftd(2*n - 1, 0);
        vector<int> rightd(2*n - 1, 0);

        solve(0, n, cols, leftd, rightd, board, ans);
        return ans;
    }    
};
