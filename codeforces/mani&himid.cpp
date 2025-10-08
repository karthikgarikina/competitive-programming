#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        string str;
        cin>>str;
        p--;
        int right=n-1,left=1;
        for(int i=p;i<n;i++){
            if(str[i]=='#'){
                right=i-1;
                break;
            }
        }
        for(int i=p;i>=0;i--){
            if(str[i]=='#'){
                left=i+2;
                break;
            }
        }
        right=(n-right);
        int maxpath=max(left,right);
        int ans=min(maxpath,p+1);
        ans=min(ans,n-p);
        cout<<ans<<"\n";
    }
}