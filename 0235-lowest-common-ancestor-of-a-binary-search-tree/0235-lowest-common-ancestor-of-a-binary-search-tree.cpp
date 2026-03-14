/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // //base cases
        // if(root == NULL){
        //     return NULL;
        // }
        // if(root->val == p->val   ||  root->val == q->val){
        //     return root;
        // }

        // //now recursion
        // TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        // TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        // //while returning 
        // if(leftAns != NULL  &&  rightAns != NULL){
        //     return root;
        // }
        // else if(leftAns == NULL  &&  rightAns != NULL){
        //     return rightAns;
        // }
        // else if(leftAns != NULL  &&  rightAns == NULL){
        //     return leftAns;
        // }
        // else{
        //     return NULL;
        // }

        // return NULL;








        //base case
        // if(root == NULL)
        //     return NULL;

        // if(root-> val < p->val  &&  root->val < q->val){
        //     return lowestCommonAncestor(root->right,p,q);
        // }

        // if(root-> val > p->val  &&  root->val > q->val){
        //     return lowestCommonAncestor(root->left,p,q);
        // }

        // //else case return root as it is
        // //if(root-> val == q->val  &&  root->val == q->val)
        // return root;

        // if root < p AND root < q → both nodes are in right subtree
        // if root > p AND root > q → both nodes are in left subtree
        // otherwise root is LCA






        //same in iterative way 
        //to save space -> O(1)

        while(root != NULL){
            if(root-> val < p->val  &&  root->val < q->val){
                root = root->right;
            }
            else if(root-> val > p->val  &&  root->val > q->val){
                root = root->left;
            }
            else{
                return root;
            }
        }
        return NULL;
    }
};