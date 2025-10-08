#include<bits/stdc++.h>
using namespace std;
int main(){
    int d,u;
    cin>>d>>u;
    int time=((d-1)*(d-2))/2;
    int fuel,rem;
    if(u>=time){
        fuel=0;
        rem=u-time;
    }
    else{
        fuel=time-u;
        rem=0;
    }
    cout<<(d+fuel)<<" "<<rem;
}


// int maxcount(vector<int>&arr, int num){
//     int cnt=0;
//     for(auto i : arr){
//         if(i>num) cnt++;
//     }
//     return cnt;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     vector<int>first,second;
//     first.push_back(arr[0]);
//     second.push_back(arr[1]);
//     for(int i=2;i<n;i++){
//         int a=maxcount(first,arr[i]),b=maxcount(second,arr[i]);
//         if(a>b){
//             first.push_back(arr[i]);
//         }
//         else if(b>a){
//             second.push_back(arr[i]);
//         }
//         else{
//             if(first.size()>second.size()) second.push_back(arr[i]);
//             else first.push_back(arr[i]);
//         }
//     }

// }