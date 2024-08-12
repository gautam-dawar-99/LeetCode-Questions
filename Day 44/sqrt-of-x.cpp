// problem link : https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
        long long l=0,r=x;
        long long ans=-1;
        while(l<=r){
            long long mid=(l+r)/2;
            if(mid*mid==x){
                return mid;
            }
            else if(mid*mid<x){
                ans=mid;
                l=mid+1;

            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};