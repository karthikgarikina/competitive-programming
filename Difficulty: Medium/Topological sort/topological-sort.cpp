class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int>indegree(V);
        vector<vector<int>>adj(V);
        for(auto i : edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
        }
        for(auto i : adj){
            for(auto j : i) indegree[j]++;
        }
        queue<int>Q;
        for(int i=0;i<V;i++){
             if(indegree[i]==0) Q.push(i);
        }
        vector<int>topo;
        while(!Q.empty()){
            auto node=Q.front();
            Q.pop();
            topo.push_back(node);
            for(auto i : adj[node]){
                indegree[i]--;
                if(indegree[i]==0) Q.push(i);
            }
        }
        return topo;
        
    }
};