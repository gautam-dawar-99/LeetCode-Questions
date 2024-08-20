// problem link : https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/description/
#define ll long long
class Solution {
public:
    int n;
    ll dp[100001][3];
    ll solve(vector<int>& nums1, vector<int>& nums2, int i, int flag) {
        if (i >= n) {
            return 0;
        }
        if (dp[i][flag] != -1) {
            return dp[i][flag];
        }
        ll ans = 0;
        if (flag == 0) {
            ll temp1 = nums1[i] + solve(nums1, nums2, i + 1, flag);
            ll temp2 = nums1[i] + solve(nums1, nums2, i + 2, 1 - flag);
            ans = max(temp1, temp2);
        } else {
            ll temp1 = nums2[i] + solve(nums1, nums2, i + 1, flag);
            ll temp2 = nums2[i] + solve(nums1, nums2, i + 2, 1 - flag);
            ans = max(temp1, temp2);
        }

        return dp[i][flag] = ans;
    }
    long long maxEnergyBoost(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        n = nums1.size();
        ll ans1 = solve(nums1, nums2, 0, 0);
        memset(dp, -1, sizeof(dp));
        ll ans2 = solve(nums1, nums2, 0, 1);
        return max(ans1, ans2);
    }
};