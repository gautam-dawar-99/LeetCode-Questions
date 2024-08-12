// problem link : https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        double ans;
        int m = arr1.size();
        int n = arr2.size();
        vector<int> merged(arr1.size() + arr2.size());
        merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(),
              merged.begin());
        // for(auto it:merged){
        //     cout<<it<<" ";
        // }
        int sz = merged.size();
        // cout<<sz;
        if (sz % 2 == 0) {
            sz /= 2;
            ans = (merged[sz] + merged[sz - 1]);
            // cout<<"...."<<merged[sz]<<"  "<<merged[sz-1];
            ans /= 2;
        } else {
            sz /= 2;
            ans = 1.0 * (merged[sz]);
            // ans/=2;
        }
        ans *= 1.0;
        return ans;
    }
};