// Problem link : https://leetcode.com/problems/xor-queries-of-a-subarray/description/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        int x,y;
        int tmp;
        int sz=queries.size();
        for(int i=0;i<sz;i++){
            x=queries[i][0];
            y=queries[i][1];
            tmp=arr[x];
            for(int k=x+1;k<=y;k++){
                if(x==y){
                    tmp=arr[x];
                }
                tmp=tmp^arr[k];
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};