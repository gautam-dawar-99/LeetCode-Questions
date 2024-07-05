// Problem link : https://leetcode.com/problems/most-frequent-even-element/
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;          
        }
        int max=INT_MIN;
        int ans = -1;
        for(auto it:mp){
            if(it.first%2==0){
                if(it.second>max){
                    max=it.second;
                    ans=it.first;
                }
            }
        }
        return ans;
    }
};