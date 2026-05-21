#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n,k,p,m;
        cin>>n>>k>>p>>m;

        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        queue<pair<int,int>>Q;
        for(int i=0;i<n;i++){
            if(i<k and (i+1!=p)) pq.push({arr[i],i+1});
            else Q.push({arr[i],i+1});
        }

        int ans=0;

        if(k==n){
            ans=(m/arr[p-1]);
        }
        else{
            if(p<=k){
                if(m<arr[p-1]){
                    m=0;
                }
                else{
                    ans++;
                    m-=arr[p-1];
                    Q.push({arr[p-1],p});
                }
            }
            while(m>0){

                auto [val,idx]=pq.top();
                if(m<val) break;

                m-=val;
                Q.push({val,idx});
                pq.pop();

                auto [val2,idx2]=Q.front();

                if(idx2==p){
                    if(m<val2) break;

                    ans++;
                    m-=val2;

                    Q.push(Q.front());
                    Q.pop();
                }
                
                pq.push(Q.front());
                Q.pop();
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}