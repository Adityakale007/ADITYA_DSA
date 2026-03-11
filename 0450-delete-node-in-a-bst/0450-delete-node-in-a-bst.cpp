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
    TreeNode* maxVal(TreeNode* root){
        TreeNode* temp = root;
        while(temp -> right != NULL){
            temp = temp -> right;
        }
        return temp;
    }
    TreeNode* minVal(TreeNode* root){
        TreeNode* temp = root;
        while(temp -> left != NULL){
            temp = temp -> left;
        }
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if(root == NULL)
            return NULL;
        
        //first find
        if(root->val == key){
            //operate delete

            //0 CHILD
            if(root->left == NULL   &&  root->right == NULL){
                delete root;
                return NULL;
            }

            //1 child

            //LEFT CHILD
            if(root->left != NULL   &&  root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            //RIGHT CHILD
            if(root->left == NULL   &&  root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            //2 CHILD
            //either find max from left
            //or
            //find min from right

            if(root->left != NULL   &&  root->right != NULL){
                int mini = minVal(root->right) -> val;
                root->val = mini;
                root -> right = deleteNode(root->right,mini);
                return root;
            }

        }
        else if(root->val > key){
            //search left
            root -> left = deleteNode(root->left,key);
            return root;
        }
        else{
            //search right
            root -> right = deleteNode(root->right,key);
            return root;
        }

        return NULL;
    }
};