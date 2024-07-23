// Problem Link : https://leetcode.com/problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int op=0,cl=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                op++;
            }
            else if(s[i]==')'){
                cl++;
            }
            if(cl>op) op=0,cl=0;
            else if(op==cl) ans=max(ans,cl+op);
        }
        op=0,cl=0;
        for(int i=n;i>=0;i--){
            if(s[i]=='('){
                cl++;
            }
            else if(s[i]==')'){
                op++;
            }
            if(cl>op) op=0,cl=0;
            else if(op==cl) ans=max(ans,cl+op);
        }
        return ans;
    }
};