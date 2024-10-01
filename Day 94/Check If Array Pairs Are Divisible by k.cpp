// problem link : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> um;
        for(auto it:arr){
            int rem=it%k;
            if(rem<0) rem+=k;
            um[rem]++;
        }
        if(um[0]%2!=0) return false;
        
        for(int it=1;it<=k/2;it++){
            if(um[it]!=um[k-it]){
                return false;
            }
        }
        return true;
    }
};