// problem link : https://leetcode.com/problems/find-missing-observations/
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int m = rolls.size();
        // calculating the size of rolls as m and n is given we want to add it
        // up as m+n
        int expected = (n + m) * mean;
        // expected sum of all rolls
        int sum = 0;
        for (auto num : rolls) {
            sum += num;
        }
        int target = expected - sum;
        //to find the target using above 
        // cout<<expected<<" "<<sum<<" "<<target;
        // cout << target;
        if (target <= 0 || n > target || target > 6 * n) {
            return ans;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 6; j >= 1; j--) {
                // make a local copy of target for each itertaion
                int local = target;
                local -= j;
                // update value of local using j
                if (local >= n - 1 - i) {
                    target = target - j;
                    // update target
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};