// User function Template for C++

class Solution {
  public:
    bool dfs(vector<int>graph[], int node, vector<int>&visited, vector<int>&pathVisited, vector<int>&safeNode){
        visited[node]=1;
        pathVisited[node]=1;
        for(auto nyb : graph[node]){
            if(!visited[nyb]){
                if(dfs(graph,nyb,visited,pathVisited,safeNode)) return true;
            }
            else if(pathVisited[nyb]==1) return true;
        }
        pathVisited[node]=0;
        safeNode[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int>visited(n),pathVisited(n),safeNode(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited,pathVisited,safeNode);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safeNode[i]) ans.push_back(i);
        }
        return ans;
        
    }
};
