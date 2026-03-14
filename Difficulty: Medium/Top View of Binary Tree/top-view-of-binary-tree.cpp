/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        map<int,int>Map;
        queue<pair<Node*,int>>Q;
        Q.push({root,0});
        while(!Q.empty()){
            int len=Q.size();
            for(int i=0;i<len;i++){
                auto [node,posi]=Q.front();
                Q.pop();
                if(Map.find(posi)==Map.end()) Map[posi]=node->data;
                if(node->left) Q.push({node->left,posi-1});
                if(node->right) Q.push({node->right,posi+1});
            }
        }
        vector<int>ans;
        for(auto i : Map) ans.push_back(i.second);
        return ans;
    }
};