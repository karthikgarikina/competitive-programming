class Solution {
  public:
    bool Dfs(vector<vector<int>>&adj,int node,int prnt,vector<bool>&visited){
        visited[node]=true;
        for(auto i : adj[node]){
            if(i==prnt) continue; 
            if(!visited[i]){
                if(Dfs(adj,i,node,visited)) return true;
            }
            else return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto i : edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(Dfs(adj,i,-1,visited)) return true;
            }
        }
        return false;
    }
};