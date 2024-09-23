// problem link : https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/
#define ll long long
class Solution {
public:
    int helper(int prefix, ll n) {
        ll curr = prefix;
        ll next = prefix + 1;
        int cnt = 0;

        while (curr <= n) {
            cnt += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int cnt = helper(curr, n);
            if (cnt <= k) {
                curr++;
                k -= cnt;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};