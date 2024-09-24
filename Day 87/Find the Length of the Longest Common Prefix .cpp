// problem link : https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> us;

        for(auto it: arr1) {
            string n = to_string(it);
            string pre = "";

            for(char ch: n) {
                pre += ch;
                us.insert(pre);
            }
        }

        int res = 0;

        for(auto it: arr2) {
            string n = to_string(it);
            string pre = "";

            for(char ch: n) {
                pre += ch;

                if(us.count(pre)) {
                    res = max(res, (int)pre.length());
                }
                else {
                    break;
                }
            }
        }

        return res;
    }
};