//Brute Force TC -O(2^n) Gives TLE
class Solution {
    int countpaths(int i, int j, int m, int n){
        if(i == m-1 && j == n-1)
            return 1;
        if(i >= m || j >= n)
            return 0;
        return countpaths(i+1,j,m,n) + countpaths(i,j+1,m,n);
    }
public:
    int uniquePaths(int m, int n) {
        return countpaths(0,0,m,n);
    }
};

// Better DP Soln 
class Solution {
public:
    int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
     else return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       
        //dp[1][1]=1;
       int num=countPaths(0,0,m,n,dp);
        if(m==1&&n==1)
            return num;
        return dp[0][0];
    }
};

//Combinatorics Soln TC - O(n-1) or O(m-1)
int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
