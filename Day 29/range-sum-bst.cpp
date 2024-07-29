// problem link : https://leetcode.com/problems/range-sum-of-bst/
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root){
            return 0;
        }
        int sum=0;
        if(root->val>=low && root->val<=high){
            sum+=root->val;
        }
        int lst = rangeSumBST(root->left,low,high);
        int rst = rangeSumBST(root->right,low,high);

        return sum+lst+rst;
        
    }
};