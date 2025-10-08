#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        unordered_map<long long,long long>Map;
        vector<long long>arr(n);
        for(long long i=0;i<n;i++){
            cin>>arr[i];
            Map[arr[i]]++;
        }
        long long size=Map.size();
        long long ans=(size*2)-1;
        cout<<ans<<"\n";
    }
}