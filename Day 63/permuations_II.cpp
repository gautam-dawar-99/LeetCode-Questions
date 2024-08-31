// problem link : https://leetcode.com/problems/permutations-ii/
class Solution {
public:
    void solve(vector<int>& nums, int ind, vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // map for finding duplicate num
        unordered_map<int, int> umpp;
        for (int i = ind; i < nums.size(); i++) {
            // skip duplicate permutation
            if (umpp.find(nums[i]) != umpp.end())
                continue;

            umpp[nums[i]]++;
            swap(nums[i], nums[ind]);
            solve(nums, ind + 1, ans);
            // backtracking
            swap(nums[i], nums[ind]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int sz = nums.size();
        if (sz < 1){
            return ans;
        }
        // sort for the skiping the duplicates combination
        sort(nums.begin(), nums.end());
        
        solve(nums, 0, ans);
        return ans;
    }
};