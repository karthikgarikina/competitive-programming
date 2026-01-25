class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, long long dis, vector<vector<long long>>&dist, int idx, vector<char>&visited){
        visited[node]=1;
        dist[node][idx]=dis;
        for(auto i : adj[node]){
            if(!visited[i]) dfs(i,adj,dis+1,dist,idx,visited);
        } 
    }
    bool find(vector<long long>&arr){
        return (((arr[0]*arr[0])+(arr[1]*arr[1]))==(arr[2]*arr[2]));
    }


    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>>adj(n);
        for(auto i : edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<long long>>dist(n,vector<long long>(3));
        vector<char>visited(n,0);
        
        dfs(x,adj,0,dist,0,visited);
        fill(visited.begin(), visited.end(), 0);
        dfs(y,adj,0,dist,1,visited);
        fill(visited.begin(), visited.end(), 0);
        dfs(z,adj,0,dist,2,visited);

        int ans=0;
        for(auto i : dist){
            sort(i.begin(),i.end());
            if(find(i)) ans++;
        }
        return ans;  
    }
};