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
    void solve(TreeNode* root, int k,vector<long long> &path,int &cnt){
        if(root == NULL)
            return ;
        
        path.push_back(root->val);

        solve(root->left,k,path,cnt);
        solve(root->right,k,path,cnt);

        //check k sum
        long long sum = 0;
        for(int i = path.size()-1;i>=0;i--){
            sum += path[i];
            if(sum == k)
                cnt++;
        }

        //while returning
        path.pop_back();
        //but path is not passed by reference it is passed by value so we can ignore this
    }
    int pathSum(TreeNode* root, int k) {
        vector<long long>path;
        int cnt = 0;
        solve(root,k,path,cnt);
        return cnt;
    }
};