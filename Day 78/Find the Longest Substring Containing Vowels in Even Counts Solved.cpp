// problem link : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> arr(32, -2);
        arr[0] = -1;

        int max_len = 0;
        int mask = 0;

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];

            switch (ch) {
                case 'a':
                    mask ^= 1;
                    break;
                case 'e':
                    mask ^= 2;
                    break;
                case 'i':
                    mask ^= 4;
                    break;
                case 'o':
                    mask ^= 8;
                    break;
                case 'u':
                    mask ^= 16;
                    break;
            }

            int prev = arr[mask];
            if (prev == -2) {
                arr[mask] = i;
            } else {
                max_len = max(max_len, i - prev);
            }
        }

        return max_len;
    }
};