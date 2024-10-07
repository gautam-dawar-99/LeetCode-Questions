// problem link : https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto it : s){
            if(st.empty()){
                st.push(it);
            }
            else if(st.top()=='A' && it =='B'){
                st.pop();
            }
            else if(st.top()=='C' && it =='D'){
                st.pop();
            }
            else{
                st.push(it);
            }
        }
        return st.size();
    }
};