// problem link : https://leetcode.com/problems/subsets/
class Solution {
public:
    void subsets(vector<int>& nums,int i, vector<int>& an,vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(an);
            return ;
        }

        subsets(nums,i+1,an,ans);
        an.push_back(nums[i]);
        
        subsets(nums,i+1,an,ans);
        an.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> an;
        subsets(nums,0,an,ans);
        return ans;
    }
};