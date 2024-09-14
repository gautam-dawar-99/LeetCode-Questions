// problem link : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAND = *max_element(nums.begin(),nums.end());
        // cout<<maxAND;
        int maxi = 1;
        int cnt = 0;
        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] == maxAND)
            {
                while(i < nums.size() && nums[i++] == maxAND){
                    cnt++;
                }
                maxi = max(maxi,cnt);
                cnt = 0;
            }
            else i++;
        }
        return maxi;
    }
};