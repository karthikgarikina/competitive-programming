#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        ll n,k;
        cin>>n>>k;
        ll x,a,b,c;
        cin>>x>>a>>b>>c;
        vector<ll>arr(n);
        arr[0]=x;
        for(ll i=1;i<n;i++){
            arr[i]=(a*arr[i-1]+b)%c;
        }
        stack<pair<ll,ll>>in,out;
        ll st=0, ans=0;
        for(ll i=0;i<n;i++){
            if(in.empty()) in.push({arr[i],arr[i]});
            else in.push({arr[i],arr[i]|in.top().second});
            if(i-st+1==k){
                if(in.empty()) ans^=out.top().second;
                else if(out.empty()) ans^=in.top().second;
                else ans^=(out.top().second|in.top().second);

                if(out.empty()){
                    out.push({in.top().first,in.top().first});
                    in.pop();
                    while(!in.empty()){
                        out.push({in.top().first,(in.top().first|out.top().second)});
                        in.pop();
                    }
                }
                out.pop();
                st++;
            }
        }
        cout<<ans;

    return 0;
}
