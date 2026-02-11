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
    
    bool rec(TreeNode* root){
        //base
        if(root == NULL){
            return true;
        }

        bool left = rec(root -> left);
        bool right = rec(root -> right);

        bool diff = abs(height(root->left) - height(root->right)) <= 1;

        if(left && right && diff){
            return true;
        }
        return false;
    }

    pair<bool,int> rec2(TreeNode* root){
        //base
        pair<bool,int> p = make_pair(true,0);
        if(root == NULL){
            return p;
        }

        pair<bool,int> left = rec2(root -> left);
        pair<bool,int> right = rec2(root -> right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool,int> ans;
        ans.first = (leftAns && rightAns && diff);
        ans.second = max(left.second,right.second) + 1;

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        // return rec(root);
        return rec2(root).first;
    }
};