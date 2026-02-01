#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> FloydWarShall(int n,int m,vector<vector<int>>grid){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(grid[i][k]!=INT_MAX && grid[k][j]!=INT_MAX)
                grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
            }
        }
    }
    return grid;
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n+1,vector<int>(n+1,INT_MAX));
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        grid[u][v]=wt;
    }
    vector<vector<int>>ans=FloydWarShall(n,m,grid);
    for(int i=1;i<=n;i++){
        cout<<i<<"--> ";
        for(int j=1;j<=n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }   
}