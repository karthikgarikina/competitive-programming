#include<bits/stdc++.h>
using namespace std;
void solve(int col, vector<vector<string>>&ans, vector<string>&board, vector<int>&leftRow, vector<int>&upperDiagonal, vector<int>&lowerDiagonal,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && upperDiagonal[n-1 + col - row]==0 && lowerDiagonal[row+col]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[n-1 + col - row]=1;
            solve(col+1,ans,board,leftRow,upperDiagonal,lowerDiagonal,n);
            board[row][col]='.';
            leftRow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1 + col - row]=0;
        }
    }
}
void display(vector<vector<string>>ans){
    if(ans.size()==0){
        cout<<"Solution does't exist";
    }
    else{
        cout<<"Total possibilities "<<ans.size()<<": \n";
        for(auto board : ans){
            for(auto str: board){
                for(auto i : str){
                    cout<<i<<" ";
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<string>>ans;
    vector<string>board(n,string(n,'.'));
    vector<int> leftRow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
    solve(0,ans,board,leftRow,upperDiagonal,lowerDiagonal,n);
    display(ans);


    

}