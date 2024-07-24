// problem link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        if (root == nullptr)
            return ans;

        bool lToR = true;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();

            vector<int> tmp(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* front = q.front();
                q.pop();

                int idx = lToR ? i : sz-i-1;
                tmp[idx]=front->val;

                if(front->left){
                    q.push(front->left);
                }

                if(front->right){
                    q.push(front->right);
                }
            }
            lToR=!lToR;
            ans.push_back(tmp);
         
        }
        return ans;
    }
};