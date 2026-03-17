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
    void inorder(TreeNode* root,vector<int> &v){
        if(root == NULL)
            return ;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }

    TreeNode* inorderToBalancedBST(int start,int end,vector<int> &v){
        if(start > end)
            return NULL;

        int mid = start + (end - start)/2;
        TreeNode* root = new TreeNode(v[mid]);
        //for left
        root->left = inorderToBalancedBST(start,mid-1,v);
        // for right
        root->right = inorderToBalancedBST(mid+1,end,v);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        int n = v.size();
        return inorderToBalancedBST(0,n-1,v);
    }
};