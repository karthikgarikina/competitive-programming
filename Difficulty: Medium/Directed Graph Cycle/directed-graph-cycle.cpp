class Solution {
  public:
    bool DFS(vector<vector<int>>&adj,int node, int prnt,vector<int>&visited){
        visited[node]=2;
        for(auto nigh : adj[node]){
            if(visited[nigh]==1) continue;
            
            if(!visited[nigh]){
                if(DFS(adj,nigh,node,visited)) return true;
            }
            else return true;
        }
        visited[node]--;
        return false;
    }
    bool isCyclic(int n, vector<vector<int>> &edges) {
        vector<vector<int>>adj(n);
        for(auto i : edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
        }
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(DFS(adj,i,-1,visited)) return true;
            }
        }
        return false;
    }
};