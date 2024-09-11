// problem link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/?envType=daily-question&envId=2024-09-11
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int tmp = start ^ goal;  // XOR to find differing bits
        int cnt = 0;
        cout<<tmp;
        
        // count the number of 1's in tmp variable
        while (tmp > 0) {
            cnt += tmp & 1;  // Check if the least significant bit i.e. right most bit is 1
            tmp=tmp >> 1;         // Right shift to check the next bit >>
        }
        
        return cnt;
    }
};