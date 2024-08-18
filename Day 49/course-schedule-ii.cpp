// problem link : https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        cout<<numCourses;
        // int helper[numCourses]={0};
        vector<int> helper(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it : adj[i]){
                helper[it]++;
            }
        }
        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(!helper[i]){      // if(helper[i]==0)
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                helper[it]--;
                if(!helper[it]){
                    q.push(it);
                }
            }
        }
        if(topo.size()==numCourses) return topo;
        return {};
    }
};