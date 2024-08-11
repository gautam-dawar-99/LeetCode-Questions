// problem link : https://leetcode.com/problems/find-greatest-common-divisor-of-array/
class Solution {
public:
    int gcd(int x, int y) {
        int ans = x < y ? x : y;
        while (1) {
            if (x % ans == 0 && y % ans == 0) {
                break;
            }
            ans--;
        }
        return ans;
    }
    int findGCD(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        int gcd_ans = gcd(maxi, mini);
        return gcd_ans;
    }
};