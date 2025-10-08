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
void OriginalGangstar() {
    long long n;
        cin>>n;
        unordered_map<long long,vector<long long>>Map;
        vector<vector<long long>>arrays(n);
        long long ansSize=0;
        for(long long a=0;a<n;a++){
            long long size;
            cin>>size;
            vector<long long>arr(size);
            for(long long i=0;i<size;i++){
                cin>>arr[i];
                if(Map.find(i)==Map.end()) Map[i]={arr[i],size-1,a};
                else if(arr[i]<Map[i][0]) Map[i]={arr[i],size-1,a};
                else if(arr[i]==Map[i][0]){
                    Map[i]={arr[i],i,a};
                }
            }
            ansSize=max(ansSize,size);
            arrays[a]=arr;
        }
        vector<long long>ans(ansSize);
        long long st=0,ed;
        while(true){
            ed=Map[st][1];
            int a=Map[st][2];
            for(int i=st;i<=ed;i++){
                ans[i]=arrays[a][i];
            }
            st=ed+1;
            if(st>=ansSize) break;
        }
        for(auto i : ans) cout<<i<<" ";
        cout<<endl;

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
