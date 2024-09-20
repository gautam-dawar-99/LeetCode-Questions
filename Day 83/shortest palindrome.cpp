// problem link : https://leetcode.com/problems/shortest-palindrome/
class Solution {
public:
    string shortestPalindrome(string s) {
        int count = kmp(string(s.rbegin(), s.rend()), s);
        return string(s.rbegin(), s.rend()).substr(0, s.length() - count) + s;
    }

private:
    int kmp(const string &txt, const string &patt) {
        string newString = patt + '#' + txt;
        vector<int> ans(newString.length(), 0);
        int i = 1, k = 0;
        while (i < newString.length()) {
            if (newString[i] == newString[k]) {
                k++;
                ans[i] = k;
                i++;
            } else {
                if (k > 0) {
                    k = ans[k - 1];
                } else {
                    ans[i] = 0;
                    i++;
                }
            }
        }
        return ans.back();
    }
};