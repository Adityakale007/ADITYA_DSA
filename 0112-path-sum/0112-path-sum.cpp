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
    pair<bool,int> rec(TreeNode* root, int target){
        //base case
        if(root == NULL){
            pair<bool,int> p = {false,0};
            return p;
        }
        //leaf node
        if(root->left == NULL && root->right == NULL){
            return {root->val == target,root->val};
        }

        pair<bool,int> left = rec(root -> left , target - root->val);
        pair<bool,int> right = rec(root -> right , target - root->val);

        bool leftAns = left.first;
        bool rightAns = right.first;

// bool check = (left.second == target || right.second == target); as being checked in base codition

        pair<bool,int> ans;
        ans.first = (leftAns || rightAns);
        ans.second = root->val;

        return ans; 
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return rec(root,targetSum).first;
    }
};