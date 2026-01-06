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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>Q;
        Q.push(root);
        int level=0,ans=0,maxi=INT_MIN;
        while(!Q.empty()){
            int n=Q.size();
            long long sum=0;
            level++;
            for(int i=0;i<n;i++){
                auto front=Q.front();
                Q.pop();
                sum+=front->val;
                if(front->left) Q.push(front->left);
                if(front->right) Q.push(front->right);
            }
            if(sum>maxi){
                maxi=sum;
                ans=level;
            }
        }
        return ans;
    }
};