#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,total;
        cin>>n;
        cin>>total;
        bool flag=true;
        int posi,side;
        cin>>posi;
        cin>>side;
        long long ans=0;
        if(posi%2==side){
            ans+=posi;
        }
        else{
            ans+=(posi-1);
            flag=false;
        }
        int prev=posi;
        for(int i=1;i<n;i++){
            cin>>posi;
            cin>>side;
            if(posi%2==side && flag){
                ans+=(posi-prev);
            }
            else if(posi%2!=side && !flag){
                ans+=(posi-prev);
            }
            else if(posi%2!=side && flag){
                ans+=(posi-prev-1);
                flag=false;
            }
            else{
                ans+=(posi-prev-1);
                flag=true;
            }
            prev=posi;
        }
        ans+=(total-prev);
        cout<<ans<<"\n";
    }
}