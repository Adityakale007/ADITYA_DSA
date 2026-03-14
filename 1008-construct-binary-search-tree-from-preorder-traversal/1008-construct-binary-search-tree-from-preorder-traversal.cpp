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
    TreeNode* solve(vector<int>& preorder,int mini,int maxi,int &i){
        if(i >= preorder.size())
            return NULL;
        
        if(preorder[i] < mini  ||  preorder[i] > maxi){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = solve(preorder,mini,root->val,i);
        root->right = solve(preorder,root->val,maxi,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //1st approach -> simply build a tree from the vector -->> O(N2)
        //2nd approach -> sort the array ->inorder -> build tree -->> O(Nlogn)

        //for O(N) time in single traversal
        // N    L   R
        //checking based on range

        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i = 0;
        return solve(preorder,mini,maxi,i);
    }
};