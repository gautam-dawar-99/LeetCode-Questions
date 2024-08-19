// problem link : https://leetcode.com/problems/01-matrix/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dist(m,vector<int>(n,0));

        queue<pair<pair<int,int>,int>> q; // teen int values phli for row dusri for column and      tisri for steps 
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    // agar value kisi coordinate pr 0 hai toh usko queue m add krdo with distance/steps 0 in starting
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    // mark as visited
                }else{
                    vis[i][j]=0;
                    // mark as unvisited
                }
            }
        }
        // possible four moves Top Right Bottom Left
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dist[row][col]=steps;   // distance vector m steps mark kre hai 
            for(int i=0;i<4;i++){
                int nRow=row+delRow[i]; // new row yani ki ye move kr rha h row-wise
                int nCol=col+delCol[i]; // new col yani ki ye move kr rha h col-wise

                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && vis[nRow][nCol]==0){
                    vis[nRow][nCol]=1;
                    q.push({{nRow,nCol},steps+1});
                }
            }
        }
        return dist;
    }
};