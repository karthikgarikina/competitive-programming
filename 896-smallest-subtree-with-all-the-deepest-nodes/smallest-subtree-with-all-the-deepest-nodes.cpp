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
    TreeNode* findSubtree(TreeNode* root, int depth, int maxDepth){
        if(!root) return NULL;
        if(depth==maxDepth){
            return root;
        }
        TreeNode* left=findSubtree(root->left, depth+1, maxDepth);
        TreeNode* right=findSubtree(root->right, depth+1, maxDepth);

        if(!left and !right) return NULL;
        else if(left and right) return root;
        else{
            return (left)?left:right;
        }

    }
    void depthOf(TreeNode* root, int depth, int &maxDepth){
        if(!root) return;
        maxDepth=max(maxDepth,depth);
        depthOf(root->left, depth+1, maxDepth);
        depthOf(root->right, depth+1, maxDepth);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth=1;
        depthOf(root,1,maxDepth);
        return findSubtree(root,1,maxDepth);
    }
};