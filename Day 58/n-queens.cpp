// problem link : https://leetcode.com/problems/n-queens/
class Solution {
public:
    bool safeHai(vector<vector<char>> &grid,int row,int col,int n){
        // horizontally check krega ye ki queen place kr skte hai ya ni 
        for(int j=col;j>=0;j--){
            if(grid[row][j]=='Q') return false;
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q') return false;
        }
        for(int i=row,j=col;i<n&&j>=0;i++,j--){
            if(grid[i][j]=='Q') return false;
        }
        return true;
    }
void solve(vector<vector<string>> &ans,vector<vector<char>> &grid,int col,int n){
    // base case
    if(col==n){
        // print the solution
         vector<string> solution;
            for (int i = 0; i < n; i++) {
                string row(grid[i].begin(), grid[i].end());
                solution.push_back(row);
            }
            ans.push_back(solution);
            return;
    }
    // ek position pr hum place krenge baki recursion dekh lega
    for(int row=0;row<n;row++){
        if(grid[row][col]=='.'){
            if(safeHai(grid,row,col,n)){
            grid[row][col]='Q';
            // recursion
            solve(ans,grid,col+1,n);
            // backtracking
            grid[row][col] = '.';
            }
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> grid(n, vector<char>(n, '.'));
        solve(ans,grid,0,n);
        return ans;
    }
};
