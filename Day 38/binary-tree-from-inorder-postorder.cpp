// problem link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    unordered_map<int, int> um;
    int ind;
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int start,
                     int end) {
        if (start > end) {
            return nullptr;
        }
        if(ind<0){
            return nullptr;
        }
        TreeNode * root=new TreeNode(postorder[ind]);
        int mid=um[postorder[ind]];
        ind-=1;
        root->right=helper(inorder,postorder,mid+1,end);
        root->left=helper(inorder,postorder,start,mid-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        um.clear();
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            um[inorder[i]]=i;
        }
        ind = n - 1;
        return helper(inorder, postorder, 0, n - 1);
    }
};