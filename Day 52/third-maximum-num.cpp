// problem link : https://leetcode.com/problems/third-maximum-number/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int k = 3;
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.find(num) == seen.end()) {
                pq.push(num);
                seen.insert(num);

                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        if (pq.size() < k) {
            return *max_element(nums.begin(), nums.end());
        }

        return pq.top();
    }
};