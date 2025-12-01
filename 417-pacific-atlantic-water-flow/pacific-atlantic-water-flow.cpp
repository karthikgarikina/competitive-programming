class Solution {
public:
    void checkP(queue<pair<int,int>>&Q, vector<vector<bool>>&visited, vector<vector<int>>& heights, int n, int m){
        while(!Q.empty()){
            auto ij=Q.front();
            Q.pop();
            int i=ij.first,j=ij.second;
            if(i+1<n and !visited[i+1][j] and heights[i][j]<=heights[i+1][j]){
                visited[i+1][j]=true;
                Q.push({i+1,j});
            }
            if(j+1<m and !visited[i][j+1] and heights[i][j]<=heights[i][j+1]){
                visited[i][j+1]=true;
                Q.push({i,j+1});
            }
            if(i-1>=0 and !visited[i-1][j] and heights[i][j]<=heights[i-1][j]){
                visited[i-1][j]=true;
                Q.push({i-1,j});
            }
            if(j-1>=0 and !visited[i][j-1] and heights[i][j]<=heights[i][j-1]){
                visited[i][j-1]=true;
                Q.push({i,j-1});
            }
        }

    }
    void checkA(queue<pair<int,int>>&Q, vector<vector<bool>>&visited, vector<vector<int>>& heights, int n, int m){
        while(!Q.empty()){
            auto ij=Q.front();
            Q.pop();
            int i=ij.first,j=ij.second;
            if(i+1<n and !visited[i+1][j] and heights[i][j]<=heights[i+1][j]){
                visited[i+1][j]=true;
                Q.push({i+1,j});
            }
            if(j+1<m and !visited[i][j+1] and heights[i][j]<=heights[i][j+1]){
                visited[i][j+1]=true;
                Q.push({i,j+1});
            }
            if(i-1>=0 and !visited[i-1][j] and heights[i][j]<=heights[i-1][j]){
                visited[i-1][j]=true;
                Q.push({i-1,j});
            }
            if(j-1>=0 and !visited[i][j-1] and heights[i][j]<=heights[i][j-1]){
                visited[i][j-1]=true;
                Q.push({i,j-1});
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        queue<pair<int,int>>pacific,atlantic;
        vector<vector<bool>>visitedP(n,vector<bool>(m,false));
        vector<vector<bool>>visitedA(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(!visitedP[i][0]){
                pacific.push({i,0});
                visitedP[i][0]=true;
            }
            if(!visitedA[i][m-1]){
                atlantic.push({i,m-1});
                visitedA[i][m-1]=true;
            }
        }
        for(int j=0;j<m;j++){
            if(!visitedP[0][j]){
                pacific.push({0,j});
                visitedP[0][j]=true;
            }
            if(!visitedA[n-1][j]){
                atlantic.push({n-1,j});
                visitedA[n-1][j]=true;
            }
        }
        checkP(pacific,visitedP,heights,n,m);
        checkA(atlantic,visitedA,heights,n,m);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visitedP[i][j] and visitedA[i][j]) ans.push_back({i,j});
            }
        }
        return ans;

    }
};