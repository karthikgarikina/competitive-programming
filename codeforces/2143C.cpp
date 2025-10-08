#include <bits/stdc++.h>
using namespace std;

//---------------------- FAST IO -------------------------
#define FAST_STREAM ios::sync_with_stdio(false); cin.tie(nullptr);

//---------------------- Shortcuts ------------------------
//                      NO SHORTCUTS

//---------------------- Debugging -------------------------------------------------
#ifndef ONLINE_EXEC
    #define trace(x) cerr << "[ " << #x << " : "; logData(x); cerr << " ]\n";
#else
    #define trace(x)
#endif
void logData(int x) { cerr << x; }
void logData(long long x) { cerr << x; }
void logData(string x) { cerr << x; }
void logData(char x) { cerr << x; }
void logData(double x) { cerr << x; }
template<class T> 
void logData(vector<T> v) { cerr << "{"; for(auto &i : v) cerr << i << " "; cerr << "}"; }
template<class A, class B>
void logData(const pair<A,B>& p) {
    cerr << "("; logData(p.first); cerr << ", "; logData(p.second); cerr << ")";
}
template<class K, class V>
void logData(const map<K,V>& m) {
    cerr << "{";
    bool first = true;
    for (auto &kv : m) {
        if (!first) cerr << ", ";
        logData(kv.first); cerr << ": "; logData(kv.second);
        first = false;
    }
    cerr << "}";
}

//---------------------- Math Utils -----------------------
const long long MOD = 1e9 + 7;


// =======================  OG Function  =============================
vector<int> topologySort(vector<vector<int>>&adj,int n){
    vector<int>indegree(n+1,0);
    for(int i=1;i<=n;i++){
        for(auto nib : adj[i]){
            indegree[nib]++;
        }
    }
    queue<int>Q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) Q.push(i);
    }
    vector<int>topo;
    while(!Q.empty()){
        int node=Q.front();
        Q.pop();
        topo.push_back(node);
        for(auto nib : adj[node]){
            indegree[nib]--;
            if(indegree[nib]==0) Q.push(nib);
        }
    }
    return topo;
}
void OriginalGangstar() {
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        if(x>y)
        adj[u].push_back(v);
        else 
        adj[v].push_back(u);
    }
    vector<int>topo;
    topo=topologySort(adj,n);
    for(auto i : topo) cout<<i<<" ";
    cout<<"\n";

}

int main() {
    FAST_STREAM;
    
    #ifndef ONLINE_EXEC
    freopen("debug_log.txt", "w", stderr);
    #endif
    
    long long T;
    cin >> T;
    while(T--) {
        OriginalGangstar();
    }
    return 0;
}
