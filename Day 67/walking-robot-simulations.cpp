// problem link : https://leetcode.com/problems/walking-robot-simulation/
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<string, int> umm;
        for (auto it : obstacles) {
            string key = to_string(it[0]) + "+" + to_string(it[1]);
            umm[key]++;
        }
        vector<vector<int>> direc = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        // North East South West

        int dir = 1; 
        // North dir =0 , East dir=1 , South dir=2 , West dir=3
        int x = 0, y = 0;
        int maxi = 0;
        for (int it : commands) {
            if (it == -2) {
                if (dir == 0)
                    dir = 3;
                else
                    dir--;
            } else if (it == -1) {
                dir = (dir + 1) % 4;
            } else {
                int k = it;
                for (int i = 1; i <= k; i++) {
                    int newX = x + direc[dir][0];
                    int newY = y + direc[dir][1];

                    string key = to_string(newX) + "+" + to_string(newY);
                    if (umm.find(key) != umm.end()) {
                        break;
                    }
                    x = newX, y = newY;
                    maxi = max(maxi, x * x + y * y);
                }
            }
        }

        return maxi;
    }
};