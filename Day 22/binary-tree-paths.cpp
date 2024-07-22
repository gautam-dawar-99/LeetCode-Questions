// Problem Link : https://leetcode.com/problems/binary-tree-paths/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;

    void solve(TreeNode* root,string tmp)
    {
        if(!root) return ;
        if(!root->left && !root->right){
            tmp=tmp+to_string(root->val);
            ans.push_back(tmp);
            return ;
        }
        tmp=tmp+to_string(root->val);
        tmp=tmp+"->";
        solve(root->left,tmp);
        solve(root->right,tmp);

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        solve(root,"");
        return ans;
    }
};