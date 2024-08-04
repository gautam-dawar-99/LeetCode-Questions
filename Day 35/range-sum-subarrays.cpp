// problem link : https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long mod=1e9+7;
        vector<long long> subarrays;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                subarrays.push_back(sum);
            }
        }
        long long sum=0;

        sort(subarrays.begin(),subarrays.end());

        for(int i=left-1;i<=right-1;i++ ){
            sum=sum+subarrays[i];
            sum%=mod;
        }

        return sum;
    }
};