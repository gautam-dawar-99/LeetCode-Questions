// problem link : https://leetcode.com/problems/k-closest-points-to-origin/description/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int n=points.size();
        for(int i=0;i<n;i++){

            int x=points[i][0],y=points[i][1];
            
            int distance=x*x+y*y;

            pq.push({distance,i});

            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({points[pq.top().second]});
            pq.pop();
        }
        return ans;
    }
};