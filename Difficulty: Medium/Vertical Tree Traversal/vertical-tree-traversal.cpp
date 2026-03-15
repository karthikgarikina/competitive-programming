/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        map<int,vector<int>>Map;
        queue<pair<Node*,int>>Q;
        Q.push({root,0});
        while(!Q.empty()){
            int n=Q.size();
            for(int i=0;i<n;i++){
                auto [node,posi]=Q.front();
                Q.pop();
                if(Map.find(posi)==Map.end()) Map[posi]={node->data};
                else Map[posi].push_back(node->data);
                
                if(node->left) Q.push({node->left,posi-1});
                if(node->right) Q.push({node->right,posi+1});
            }
        }
        vector<vector<int>>ans;
        for(auto i : Map) ans.push_back(i.second);
        return ans;
    }
};