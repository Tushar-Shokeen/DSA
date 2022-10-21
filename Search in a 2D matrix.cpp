//74. Search a 2D Matrix


// My own solution.
//Better solution for leetcode problem. TC - O(N+logM)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int m = matrix.size(); int n = matrix[0].size();
        while(i<m){
            if(matrix[i][n-1]>=target)
                break;
            else
                i++;
        }
        if(i==m)
            return false;
        
        
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[i][mid]==target)
                return true;
            if(matrix[i][mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }

//Optimal solution TC-O(n+m) for row-wise and column-wise sorted matrix;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); int n = matrix[0].size();
        int i=0, j=n-1;
        
        while(i<m && j>=0){
            if(matrix[i][j] == target)
                return true;
            
            if(matrix[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }

// Most Optimal approach TC - O(log(n*m)).

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int n = matrix.size(); int m = matrix[0].size();
        int low = 0, high = (n*m)-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[mid/m][mid%m] == target)
                return true;
            
            if(matrix[mid/m][mid%m] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }
