// problem link : https://leetcode.com/problems/number-of-senior-citizens/
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int snr_cnt=0;
        int n=details.size();
        for(int i=0;i<n;i++){
            string age;
            int ans;
            char x=details[i][11];
            char y=details[i][12];

            age+=x;
            age+=y;
            ans=stoi(age);
            
            if(ans>60){
                snr_cnt++;
            }
        }
        return snr_cnt;
    }
};