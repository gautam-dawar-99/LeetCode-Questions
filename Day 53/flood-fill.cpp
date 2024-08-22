// problem link : https://leetcode.com/problems/flood-fill/
class Solution {
public:
    void dfs_check(int row, int col, vector<vector<int>>& ans,vector<vector<int>>& image, int inicolor, int newcolor,int delRow[], int delCol[]) {
        ans[row][col] = newcolor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && image[nrow][ncol]==inicolor && ans[nrow][ncol]!=newcolor){
                dfs_check(nrow,ncol,ans,image,inicolor,newcolor,delRow,delCol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newcolor) {
        int inicolor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,1,0,-1};
        dfs_check(sr,sc,ans,image,inicolor,newcolor,delRow,delCol);
        return ans;
    }
};