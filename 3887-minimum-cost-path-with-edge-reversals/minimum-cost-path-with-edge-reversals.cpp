class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto i : edges){
            int u=i[0],v=i[1],w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int> minCost(n, INT_MAX);
         while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if(node == n - 1) return cost;
            for(auto &[n,w] : adj[node]) {
                if(minCost[n] > cost+w) {
                    minCost[n]=cost+w;
                    pq.push({cost+w,n});
                }
            }
        }
        return -1;
    }
};