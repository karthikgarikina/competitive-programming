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
    long long mod=1e9+7;
    long long totalSum(TreeNode* root){
        if(!root) return 0;
        return (root->val)+totalSum(root->left)+totalSum(root->right);
    }
    long long findMax(TreeNode* root, long long &ans, long long &total){
        if(!root) return 0;
        long long left=findMax(root->left,ans,total);
        long long right=findMax(root->right,ans,total);
        long long val=root->val+left+right;
        long long rem=total-val;
        ans=max(ans,(rem*val));
        return val;
    }
    int maxProduct(TreeNode* root) {
        long long total=totalSum(root);
        long long ans=LLONG_MIN;
        findMax(root,ans,total);
        return ans%mod;
    }
};