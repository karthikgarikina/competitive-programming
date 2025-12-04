class Solution {
public:
    bool valid(int i, int j, int n, int m, int ci, int cj){
        return ((ci<=n and ci>=i) and (cj<=m and cj>=j));
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int i=0,j=0,n=rows-1,m=cols-1;
        vector<vector<int>>ans;
        ans.push_back({rStart,cStart});
        cStart++;
        int inc=1; 
        while(true){
            for(int k=cStart;k<cStart+inc;k++){  //right
                if(valid(i,j,n,m,rStart,k)){
                    ans.push_back({rStart,k});
                }
            }
            rStart++;
            cStart=cStart+inc-1;
            for(int k=rStart;k<rStart+inc;k++){ //down
                if(valid(i,j,n,m,k,cStart)){
                    ans.push_back({k,cStart});
                }
            }
            cStart--;
            rStart=rStart+inc-1;
            for(int k=cStart;k>cStart-inc-1;k--){ //left
                if(valid(i,j,n,m,rStart,k)){
                    ans.push_back({rStart,k});
                }
            }
            rStart--;
            cStart=cStart-inc;
            for(int k=rStart;k>rStart-inc-1;k--){ //top
                if(valid(i,j,n,m,k,cStart)){
                    ans.push_back({k,cStart});
                }
            }
            cStart++;
            rStart=rStart-inc;

            if(ans.size()==(rows*cols)) break;
            inc+=2;
        }
        return ans;
    }
};