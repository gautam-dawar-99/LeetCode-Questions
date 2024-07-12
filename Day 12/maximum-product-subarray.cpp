// Problem Link : https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long n = nums.size();
        long long maxi=nums[0];
        long long Pro=1;
        for(int i=0;i<n;i++){
            Pro=1;
            for(int j=i;j<n;j++){
                Pro*=nums[j];
                if(Pro>maxi) maxi=Pro;
                if(Pro>=1e10 || Pro<=-1e10) break;
            }
        }
        return maxi;
    }
};