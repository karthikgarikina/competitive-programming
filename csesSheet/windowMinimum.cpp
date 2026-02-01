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
    long long n,k;
    cin>>n>>k;
    long long x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<long long>arr(n);
    arr[0]=x;
    for(long long i=1;i<n;i++) arr[i]=(a*arr[i-1]+b)%c;
    deque<long long>dq;
    long long st=0,minXor=0;
    for(int i=0;i<n;i++){
        while(!dq.empty() and dq.back()>arr[i]){
            dq.pop_back();
        }
        dq.push_back(arr[i]);
        
        if((i-st+1)==k){
            minXor^=dq.front();
            if(dq.front()==arr[st]){
                dq.pop_front();
            }
            st++;
        }
    }
    cout<<minXor<<endl;
}

int main() {
    FAST_STREAM;
    
    #ifndef ONLINE_EXEC
    freopen("debug_log.txt", "w", stderr);
    #endif
    
    OriginalGangstar();

    // long long T;
    // cin >> T;
    // while(T--) {
    //     OriginalGangstar();
    // }
    return 0;
}
