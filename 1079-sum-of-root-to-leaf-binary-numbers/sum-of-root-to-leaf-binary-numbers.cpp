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
    int sum=0;
    void find(TreeNode* root, int value){
        value=(value<<1);
        if(root->val==1){
            value++;
        }
        if(!root->left and !root->right){
            sum+=value;
            return;
        }
        if(root->left) find(root->left,value);
        if(root->right) find(root->right,value);
    }
    int sumRootToLeaf(TreeNode* root) {
        int value=(0>>1);
        find(root,value);
        return sum;
    }
};