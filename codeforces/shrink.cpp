#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        int i=0,j=n-1;
        for(int num=1;num<=n;num++){
            if(num%2!=0){
                arr[i]=num;
                i++;
            }
            else{
                arr[j]=num;
                j--;
            }
        }
        for(auto num : arr) cout<<num<<" ";
        cout<<"\n";
    }
}