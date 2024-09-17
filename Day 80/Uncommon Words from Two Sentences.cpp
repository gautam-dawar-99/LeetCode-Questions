// problem link : https://leetcode.com/problems/uncommon-words-from-two-sentences/
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        string word="";
        for(auto p:s1){
            if(p==' '){
                mp[word]++;
                word.clear();
                word="";
            }else{
                word+=p;
            }
        }
        mp[word]++;
        word.clear();
        word="";
        for(auto p:s2){
            if(p==' '){
                mp[word]++;
                word.clear();
                word="";
            }else{
                word+=p;
            }
        }
        mp[word]++;
        vector<string> res;
        for(auto p:mp){
            if(p.second==1){
                res.push_back(p.first);
            }
        }
        return res;
    }
};