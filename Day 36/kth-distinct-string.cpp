// problem link : https://leetcode.com/problems/kth-distinct-string-in-an-array/
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> um;
        for(auto it:arr){
            um[it]++;
        }

        int cnt=0;
        for(auto it : arr){
            if(um[it]==1){
                cnt++;
                if(cnt==k) return it;
            }
        }

        return "";
    }
};