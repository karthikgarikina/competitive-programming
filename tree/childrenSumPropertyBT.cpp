#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
class Solution{
    void changeTree(TreeNode* root){
        if(!root) return;
        int sum=0;
        if(root->left) sum+=root->left->val;
        if(root->right) sum+=root->right->val;

        if(root->val<=sum) root->val=sum;
        else{
            if(root->left) root->left->val=root->val;
            if(root->right) root->right->val=root->val;
        }

        int tot=0;
        if(root->left) tot+=root->left->val;
        if(root->right) tot+=root->right->val;
        if(root->left or root->right) root->val=tot;
    }
};