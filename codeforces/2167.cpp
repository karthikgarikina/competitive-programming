#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        bool odd=false,even=false;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2==0) even++;
            else{
                odd++;
            }
        }
        if(even and odd){
            sort(arr.begin(),arr.end());
        }
        for(auto i : arr){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}