#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,posi;
        cin>>n>>posi;
        int temp;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>temp;
            mini=min(mini,temp);
            maxi=max(maxi,temp);
        }
        int left=abs(posi-mini),right=abs(posi-maxi),ans=abs(maxi-mini);
        if(left<right){
            ans+=left;
        }
        else{
            ans+=right;
        }
        cout<<ans<<"\n";
    }
}