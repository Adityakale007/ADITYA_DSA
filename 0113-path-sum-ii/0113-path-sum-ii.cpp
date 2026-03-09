class Solution {
public:

    void solve(TreeNode* root, int k,int sum, vector<int>& path, vector<vector<int>>& ans){
        
        if(root == NULL){
            return ;
        }

        path.push_back(root->val);
        sum += root->val;

        solve(root->left, k,sum, path, ans);
        solve(root->right, k,sum, path, ans);

        //while returning
        if(root->left == NULL && root->right == NULL    &&  sum == k){
            ans.push_back(path);
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int k) {

        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;

        solve(root, k,sum, path, ans);

        return ans;
    }
};