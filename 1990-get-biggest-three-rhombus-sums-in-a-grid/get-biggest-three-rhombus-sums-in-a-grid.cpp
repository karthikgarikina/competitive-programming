class Solution {
public:
    int findsum(vector<vector<int>>&grid, int i, int j, int len){
        int sum=0;
        int temp=len;
        while(temp--){
            sum+=grid[i][j];
            i++,j--;
        }
        temp=len;
        while(temp--){
            sum+=grid[i][j];
            i++;
            j++;
        }
        temp=len;
        while(temp--){
            sum+=grid[i][j];
            i--;
            j++;
        }
        temp=len;
        while(temp--){
            sum+=grid[i][j];
            i--;
            j--;
        }

        return sum;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        set<int>st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                st.insert(grid[i][j]);
                int len=1;
                while((j-len)>=0 and (j+len)<n and (i+(2*len))<m){
                    int sum=findsum(grid,i,j,len);
                    st.insert(sum);
                    len++;
                }
            }
        }
        vector<int>ans;
        int k=3;
        for(auto it = st.rbegin(); it != st.rend() && k--; it++){
            ans.push_back(*it);
        }
        return ans;
    }
};