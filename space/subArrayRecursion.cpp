#include<bits/stdc++.h>
using namespace std;
void Recurion(vector<int>arr, vector<vector<int>>&subArrs, vector<int>&curArr, int idx){
    if(idx<0){
        subArrs.push_back(curArr);
        return;
    }
    curArr.push_back(arr[idx]);
    Recurion(arr,subArrs,curArr,idx-1);
    curArr.pop_back();
    Recurion(arr,subArrs,curArr,idx-1);
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>>subArrs;
    vector<int>curArr;
    Recurion(arr,subArrs,curArr,n-1);
    cout<<"Sub Arrays Size: "<<subArrs.size()<<endl;
    for(auto A : subArrs){
        for(auto n : A){
            cout<<n<<" ";
        }
        cout<<endl;
    }

}