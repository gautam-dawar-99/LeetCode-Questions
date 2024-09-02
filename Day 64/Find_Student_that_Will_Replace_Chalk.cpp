// problem link : https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalk = 0;
        for (int amount : chalk) {
            totalChalk += amount;
        }
        k = k % totalChalk;
        for (int i = 0; i < chalk.size(); i++) {
            if (chalk[i] > k) {
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};