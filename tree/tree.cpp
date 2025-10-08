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
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL)
        return new TreeNode(val);
    
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    
    return root;
}

// Inorder Traversal
void inorder(TreeNode* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(TreeNode* root) {
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(TreeNode* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Level Order Traversal (BFS)
void levelOrder(TreeNode* root) {
    if (root == NULL)
        return;
    
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}
vector<vector<int>> traversals(TreeNode* root){
     vector<int>preorder,inorder,postorder;
     stack<pair<TreeNode*,int>>st;
     st.push({root,1});
     while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            preorder.push_back(it.first->val);
            st.push({it.first,2});
            if(it.first->left) st.push({it.first->left,1});
        }
        else if(it.second==2){
            inorder.push_back(it.first->val);
            st.push({it.first,3});
            if(it.first->right) st.push({it.first->right,1});
        }
        else if(it.second==3) postorder.push_back(it.first->val);
     }
     return {preorder,inorder,postorder};
}

// Driver Code
int main() {
    TreeNode* root = NULL;
    vector<int> values = {10, 5, 20, 3, 7, 15, 25};

    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // cout << "Preorder Traversal: ";
    // preorder(root);
    // cout << endl;

    // cout << "Postorder Traversal: ";
    // postorder(root);
    // cout << endl;

    // cout << "Level Order Traversal: ";
    // levelOrder(root);
    // cout << endl;

    // vector<vector<int>>iet_traversals=traversals(root);
    // cout<<"\n"<<"\n";
    // for(auto i : iet_traversals){
    //     for(auto j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }


    return 0;
}
