// problem link : https://leetcode.com/problems/make-sum-divisible-by-p/description/
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;  // Use long long to avoid overflow
        for (int it : nums) {
            sum += it;
        }
        int rem = sum % p;

        // If the total sum is already divisible by p, return 0
        if (rem == 0) {
            return 0;
        }

        return helper(nums, p, rem);
    }
    int helper(vector<int>& nums, int p, int rem) {
        long long prefixSum = 0;  // Use long long to avoid overflow
        int mini = nums.size();
        map<int, int> prefixMap;
        prefixMap[0] = -1;  // Initial condition for no subarray

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int targetrem = (prefixSum % p - rem + p) % p;

            if (prefixMap.find(targetrem) != prefixMap.end()) {
                mini = min(mini, i - prefixMap[targetrem]);
            }

            prefixMap[prefixSum % p] = i;
        }

        return mini < nums.size() ? mini : -1;
    }
};