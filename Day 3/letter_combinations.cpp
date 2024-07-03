// Problem Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    string arr[10]={".",".","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n;
    void solve(string& digits,string& current,vector<string> &output,int i){
        if(i==n){
            output.push_back(current);
            return ;
        }
        int digit= digits[i]-'0';
        string tmp=arr[digit];
        for(int j=0;j<tmp.size();j++){
            current.push_back(tmp[j]);
            solve(digits,current,output,i+1);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n= digits.size();
        vector<string> output;
        if (n == 0) return output; 
        string current;
        solve(digits,current,output,0);   
        return output;     
    }
};