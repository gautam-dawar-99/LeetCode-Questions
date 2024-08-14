// problem link : https://leetcode.com/problems/height-checker/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> vec(heights);
        sort(vec.begin(),vec.end());
        int cnt=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=vec[i]){
                cnt++;
            }
        }
        return cnt;
    }
};