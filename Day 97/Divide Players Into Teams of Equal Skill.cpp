// problem link : https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        int n = skill.size();
        for(auto it: skill){
            sum += it;
        }
        
        if(sum % (n/2) != 0) {
            return -1;
        }

        sort(skill.begin(), skill.end());


        int i=0, j=n-1;
        long long res = 0;

        int team = sum / (n/2);

        while(i < j) {
            if(skill[i] + skill[j] != team) return -1;
            res += (skill[i++] * skill[j--]);
        }

        return res;
    }
};