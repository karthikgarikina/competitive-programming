#include<bits/stdc++.h>
using namespace std;
int main(){
    int b1,m1,b2,m2,b3,m3,x;
    cin>>b1>>m1>>b2>>m2>>b3>>m3;
    vector<vector<int>>ans;
    x=min(b2-m2,m1);
    m1-=x;
    m2+=x;

    x=min(b3-m3,m2);
    m2-=x;
    m3+=x;

    x=min(b1-m1,m3);
    m3-=x;
    m1+=x;
    ans.push_back({m1,m2,m3});

    x=min(b2-m2,m1);
    m1-=x;
    m2+=x;
    ans.push_back({m1,m2,m3});

    x=min(b3-m3,m2);
    m2-=x;
    m3+=x;
    ans.push_back({m1,m2,m3});
    int idx=100%3;
    for(auto i : ans[idx]){
        cout<<i<<"\n";
    }

}
