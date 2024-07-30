// problem link : https://leetcode.com/problems/validate-binary-search-tree/
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
    vector<int> ans;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    bool check(vector<int> ans){
        int n=ans.size();
        bool flag=true;
        for(int i=1;i<n;i++){
            if(ans[i]<=ans[i-1]){
                flag=false;
                break;
            }
        }
        return flag;
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return check(ans);
    }
};