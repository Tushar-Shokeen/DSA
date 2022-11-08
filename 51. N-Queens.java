//Optimal Soln
class Solution {

    public void saveBoard(char[][] board, List<List<String>> ans){
        String row = "";
        List<String> newBoard = new ArrayList<>();

        for(int i=0; i<board.length; i++){
            row = "";
            for(int j=0; j<board[0].length; j++){
                if(board[i][j] == 'Q')
                    row += 'Q';
                else
                    row += '.';
            }
            newBoard.add(row);
        }

        ans.add(newBoard);
    }

    public void solve(int row, int n, int[] rows, int[] leftd, int[] rightd, char[][] board, List<List<String>> ans){
        if(row == n){
            saveBoard(board, ans);
            return;
        }

        for(int col = 0; col<n ; col++){
            if(rows[col] == 0 && leftd[row+col] == 0 && rightd[n-1 + col-row] == 0){
                board[row][col] = 'Q';
                rows[col] = 1;
                leftd[row+col] = 1;
                rightd[n-1 + col-row] = 1;
                solve(row+1, n, rows, leftd, rightd, board, ans);
                board[row][col] = '.';
                rows[col] = 0;
                leftd[row+col] = 0;
                rightd[n-1 + col-row] = 0;
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        char[][] board = new char[n][n];

        int[] rows = new int[n];
        int[] leftd = new int[2*n - 1];
        int[] rightd = new int[2*n - 1];
 
        solve(0, n, rows, leftd, rightd, board, ans);
        return ans;
    }
}


// Recursive Soln
class Solution {

    public Boolean isSafe(int row, int col, char[][] board){
        for(int i = 0; i<row ; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        int r = row;
        int c = col;

        while(r>=0 && c>=0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;
            c--;
        }

        r = row;
        c = col;

        while(r>=0 && c<board.length){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;
            c++;
        }

        return true;
    }

    public void saveBoard(char[][] board, List<List<String>> ans){
        String row = "";
        List<String> newBoard = new ArrayList<>();

        for(int i=0; i<board.length; i++){
            row = "";
            for(int j=0; j<board[0].length; j++){
                if(board[i][j] == 'Q')
                    row += 'Q';
                else
                    row += '.';
            }
            newBoard.add(row);
        }

        ans.add(newBoard);
    }

    public void solve(int row, int n, char[][] board, List<List<String>> ans){
        if(row == n){
            saveBoard(board, ans);
            return;
        }

        for(int col = 0; col<n ; col++){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';
                solve(row+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        char[][] board = new char[n][n];

        solve(0, n, board, ans);
        return ans;
    }
}
