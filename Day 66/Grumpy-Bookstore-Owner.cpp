// problem link : https://leetcode.com/problems/grumpy-bookstore-owner/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int i = 0, j = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum = sum + (grumpy[i] == 0 ? customers[i] : 0);

        int res = 0;
        while (j < n) {
            if (grumpy[j] == 1) {
                sum += customers[j];
            }

            if (j - i + 1 > minutes) {
                sum -= (grumpy[i] == 1 ? customers[i] : 0);
                i++;
            }
            if (j - i + 1 == minutes) {
                res = max(res, sum);
            }
            j++;
        }
        return res;
    }
};