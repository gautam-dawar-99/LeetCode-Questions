// Problem link : https://leetcode.com/problems/pass-the-pillow/
class Solution {
public:
    int passThePillow(int n, int time) {
        int ans=1;
        int step=1;
        while(time>0){
            ans+=step;
            if(ans==1||ans==n){
                step*=-1;
            }
            time--;
        }
        return ans;
    }
};