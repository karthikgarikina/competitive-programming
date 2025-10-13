class Solution {
  private:
    void dfs(vector<vector<int>>&adj, int node, vector<bool>&visited, stack<int>&S){
        visited[node]=true;
        for(auto nib : adj[node]){
            if(!visited[nib]) dfs(adj,nib,visited,S);
        }
        S.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto edg : edges){
            int u=edg[0],v=edg[1];
            adj[u].push_back(v);
        }
        vector<bool>visited(V,false);
        stack<int>S;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,i,visited,S);
            }
        }
        vector<int>ans;
        while(!S.empty()){
            ans.push_back(S.top());
            S.pop();
        }
        return ans;
    }
};