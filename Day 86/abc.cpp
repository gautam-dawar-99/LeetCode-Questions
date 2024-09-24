// problem link : https://leetcode.com/problems/extra-characters-in-a-string/
class Solution {
public:
    int dp[51];
    int n;
    unordered_map<string,int> um;
    int solve(int i,string& s){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        string temp="";
        for(int k=i;k<n;k++){
            temp+=s[k];
            if(um.count(temp)){
                // include
                ans=max(ans,k-i+1+solve(k+1,s));
            }
        }
        // not include
        ans=max(ans,solve(i+1,s));

        return dp[i]= ans;
    }
    int minExtraChar(string s, vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        n=s.size();
        for(auto e:words){
            um[e]++;
        }
        int ans=solve(0,s);
        //cout<<ans<<endl;
        return n-solve(0,s);
        
    }
};