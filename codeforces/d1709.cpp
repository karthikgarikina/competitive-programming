#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,pair<int,int>>Map;
        unordered_map<pair<int,int>,int>idx;
        for(int i=1;i<=2;i++){
            for(int j=1;j<=n;j++){
                int val;
                cin>>val;
                Map[val]={i,j};
                idx[{i,j}]=val;
            }
        }
        vector<pair<int,int>>ans;
        for(int i=1;i<=n;i++){
            int a=Map[i].first,b=Map[i].second;
            if(a==2){
                ans.push_back({3,i});
                int val=idx[{1,b}];
                Map[i]={1,b};
                idx[{1,b}]=i;
                idx[{2,b}]=val;
                Map[val]={2,b};
            }
            a=1;
            for(int j=b;j>i;j--){
                int val=idx[{a,j-1}];
                Map[i]=
            }

        }
    }
}