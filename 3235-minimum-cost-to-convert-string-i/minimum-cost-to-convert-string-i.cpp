class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cst) {
        vector<vector<pair<int,int>>>adj(26);
        vector<vector<long long>>cost(26,vector<long long>(26,-1));
        int n=original.size();
        for(int i=0;i<n;i++){
            int u=(original[i]-'a'), v=(changed[i]-'a'), c=cst[i];
            adj[u].push_back({v,c});
        }

        int m=source.size();
        long long ans=0;
        for(int i=0;i<m;i++){
            int s=(source[i]-'a'), t=(target[i]-'a');
            if(s==t) continue;
            else if(cost[s][t]!=-1) ans+=cost[s][t];
            else{
                vector<long long>minCost(26,INT_MAX);
                priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
                pq.push({0,s});
                long long cst=0;
                bool flag=true;
                while(!pq.empty()){
                    auto [c,node]=pq.top();
                    pq.pop();
                    if(node==t){
                        cost[s][t]=c;
                        ans+=c;
                        flag=false;
                        break;
                    }
                    for(auto &[n,w] : adj[node]){
                        if(minCost[n]>c+w){
                            minCost[n]=c+w;
                            pq.push({c+w,n});
                        }
                    }
                }
                if(flag) return -1;
            }
        }
        return ans;
    }
};