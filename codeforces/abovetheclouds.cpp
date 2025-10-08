#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool ans=false;
        unordered_map<char,int>Map;
        Map[s[0]]++;
        for(int i=1;i<n-1;i++){
            if(Map.find(s[i])!=Map.end()){
                ans=true;
                break;
            }
            Map[s[i]]++;
        }
        if(Map[s[0]]>1 || s[0]!=s[n-1]){
            if(Map.find(s[n-1])!=Map.end()){
                ans=true;
            }
        }
        if(ans) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }
}