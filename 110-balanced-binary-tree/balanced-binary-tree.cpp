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
    int check(TreeNode* root){
        if(!root) return 0;
        int lf=check(root->left),rg=check(root->right);
        if(lf==-1 || rg==-1) return -1;
        if(abs(lf-rg)>1) return -1;
        return max(lf,rg)+1;
    }
    bool isBalanced(TreeNode* root) {
        return check(root)!=-1;
    }
};