// problem link : https://leetcode.com/problems/sentence-similarity-iii/description/
class Solution {
public:

    vector<string> solve(string &s) {
        vector<string> words;
        stringstream input(s);
        string word;
        while (input >> word) {
            words.push_back(word);
        }
        return words;
    }
  bool areSentencesSimilar(string s, string t) {

        vector<string> tmp1 = solve(s);
        vector<string> tmp2 = solve(t);

        int i = 0;
        int j = 0;
        int m=tmp1.size();
        int n=tmp2.size();

        while (i < m && i < n && tmp1[i] == tmp2[i]) {
            i++;
        }

        while (j < m && j < n && tmp1[m - 1 - j] == tmp2[n - 1 - j]) {
            j++;
        }

        return (i + j >= m || i + j >= n);
    }

};