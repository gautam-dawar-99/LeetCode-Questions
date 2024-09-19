// problem link : https://leetcode.com/problems/different-ways-to-add-parentheses/description/
class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;
        for (int i = 0; i < exp.size(); ++i) {
            char oper = exp[i];
            if (oper == '+' || oper == '-' || oper == '*') {
                vector<int> s1 = diffWaysToCompute(exp.substr(0, i));
                vector<int> s2 = diffWaysToCompute(exp.substr(i + 1));
                for (int a : s1) {
                    for (int b : s2) {
                        if (oper == '+') ans.push_back(a + b);
                        else if (oper == '-') ans.push_back(a - b);
                        else if (oper == '*') ans.push_back(a * b);
                    }
                }
            }
        }
        if (ans.empty()){
            ans.push_back(stoi(exp));
        }
        return ans;
    }
};