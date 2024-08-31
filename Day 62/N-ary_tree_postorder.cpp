// problem link : https://leetcode.com/problems/n-ary-tree-postorder-traversal/

class Solution {
public:
    vector<int> ans;
    void solve(Node* root){
        if(!root)
            return ;
        for(auto node:root->children){
            solve(node);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        ans.clear();
        solve(root);
        return ans;
    }
};