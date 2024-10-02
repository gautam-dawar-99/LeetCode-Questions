// problem link : https://leetcode.com/problems/rank-transform-of-an-array/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       int n=arr.size();
       vector<pair<int,int>> vp;
       for(int i=0;i<n;i++){
         vp.push_back({arr[i],i});
       }
       sort(vp.begin(),vp.end());
       vector<int> ans(n);
       int rank=1;
       for(int i=0;i<n;i++){
        if(i>0 && vp[i].first==vp[i-1].first){
            ans[vp[i].second]=ans[vp[i-1].second];
        }
        else{
            ans[vp[i].second]=rank;
            rank++;
        }
       }
       return ans;

    }
};