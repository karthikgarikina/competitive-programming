#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int key=arr[0],idx,median=(n-1)/2;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]==key){
                idx=i;
                break;
            }
        }
    }
}