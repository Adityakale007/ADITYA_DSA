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
    // void inorder(TreeNode* root,vector<int>&v){
    //     if(root == NULL)
    //         return ;
        
    //     inorder(root->left,v);
    //     v.push_back(root->val);
    //     inorder(root->right,v);
    // }

    
    // bool isSorted(vector<int>v){
    //     int n = v.size();

    //     if(n == 0   ||  n == 1)return true;

    //     for(int i=0;i<n-1;i++){
    //         if(v[i] >= v[i+1])return false;
    //     }
    //     return true;
    // }

    bool isBST(TreeNode* root,int min,int max){
        //base case
        if(root == NULL)
            return true;
        
        if(root -> val <= min    ||  root -> val >= max){
            return false;
        }

        return (isBST(root->left,min,root->val)  &&  isBST(root->right,root->val,max));
    }
    
    bool isValidBST(TreeNode* root) {
        // vector<int>v;
        //we know in BST inorder traversal is sorted
        // inorder(root,v);
        // return isSorted(v);

        // checking with O(1) space
        //without inorder traversal
        return isBST(root,INT_MIN,INT_MAX);
    }
};