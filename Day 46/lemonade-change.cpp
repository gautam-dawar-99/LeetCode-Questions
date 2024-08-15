// problem link : https://leetcode.com/problems/lemonade-change/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                um[bills[i]]++;
            }
            else if(bills[i]==10){
                if(um[5]>=1){
                    um[5]-=1;
                    um[10]++;
                }else{
                    return false;
                }
            }
            else{
                if(um[10]>=1 && um[5]>=1){
                    um[5]-=1;
                    um[10]-=1;
                    um[20]++;
                }
                else if(um[5]>=3){
                    um[5]-=3;
                    um[20]++;
                }
                else{
                    return false;
                }
            }
        }
        
        return true;
    }
};