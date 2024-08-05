// problem link : leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    unordered_map<int,int> um;
    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int l,int r,int& ind){
        if(l>r) 
            return NULL;
        int k=um[preorder[ind]];
        TreeNode* root=new TreeNode(preorder[ind]);
        ind+=1;
        root->left=helper(preorder,inorder,l,k-1,ind);
        root->right=helper(preorder,inorder,k+1,r,ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        um.clear();
        int n=preorder.size();
        for(int i=0;i<n;i++){
            um[inorder[i]]=i;
        }
        int ind=0;
        return helper(preorder,inorder,0,n-1,ind);
    }
};