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
    int inorder(TreeNode* root, int k,int &i){
        if(root == NULL)
            return -1;

        //L
        int left = inorder(root->left,k,i);
        //if left call found the answer
        if(left != -1)
            return left;

        //N
        i++;
        if(i == k){
            return root->val;
        }

        //R
        int right = inorder(root->right,k,i);
        if(right != -1)
            return right;
        
        //can't find
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return inorder(root,k,i);
    }
};