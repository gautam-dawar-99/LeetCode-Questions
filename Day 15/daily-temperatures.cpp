//  Problem Link : https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> ngr(vector<int>&temp,int n){
        stack<int> st;
        vector<int> ans(n,-1);

        ans[n-1]=-1;
        st.push(n-1);

        for(int i=n-2;i>=0;i--){
            while(!st.empty() && temp[st.top()]<=temp[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();

            st.push(i);
        }
        return ans;

    }
        vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans_idx=ngr(temperatures,n);
        vector<int>res(n);

        for(int i=0;i<n;i++){
           if(ans_idx[i]==-1){
                res[i]=0;
           }
           else{
            res[i]=ans_idx[i]-i;
           }
        }
        return res;
    }
};