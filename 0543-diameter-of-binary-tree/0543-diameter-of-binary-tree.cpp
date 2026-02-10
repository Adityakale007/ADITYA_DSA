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
    int height(TreeNode* root){
        //base condition
        if(root == NULL){
            return 0;
        }

        int left = height(root -> left);
        int right = height(root -> right);

        int ans = max(left,right) + 1;

        return ans;
    }

    int rec(TreeNode* root){
        // base case
        if(root == NULL){
            return 0;
        }

        int op1 = diameterOfBinaryTree(root -> left);
        int op2 = diameterOfBinaryTree(root -> right);
        int op3 = height(root -> left) + height(root -> right) + 1;//root itself

        int ans = max(op1 , max(op2, op3));
        return ans;
    }

    pair<int,int> rec2(TreeNode* root){
        //base case
        pair<int,int> p = make_pair(0,0);
        if(root == NULL){
           return p;
        }
        //int this pair<int,int> -->> i have stored diameter in first block and height in second block

        pair<int,int> left = rec2(root -> left);
        pair<int,int> right = rec2(root -> right);

        int op1 = left.first;   //diameter
        int op2 = right.first;  //diameter
        int op3 = left.second + right.second + 1;  //height

        // int op1 = diameterOfBinaryTree(root -> left);
        // int op2 = diameterOfBinaryTree(root -> right);
        // int op3 = height(root -> left) + height(root -> right) + 1//root itself
 
        pair<int,int> ans;
        ans.first = max(op1 , max(op2, op3));   //diameter
        ans.second = max(left.second , right.second) + 1;   //height
        return ans;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        //here also recursion
        
        // return rec(root);
        return rec2(root).first - 1; // -1 ==>> as number of edges asked
    }
};