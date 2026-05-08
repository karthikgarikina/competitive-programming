class unionfind {
    public:
    vector<int>parent,size;
    unionfind(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int getParent(int i){
        if(parent[i]==i) return i;
        return parent[i]=getParent(parent[i]);
    }
    void connect(int i, int j){
        int par1=getParent(i),par2=getParent(j);
        if(par1==par2) return;
        int size1=size[par1],size2=size[par2];
        if (size1 >= size2) {
            parent[par2] = par1;
            size[par1] += size2;
            size[par2] = 0; 
        }
        else{
            parent[par1] = par2;
            size[par2] += size1;
            size[par1] = 0;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unionfind uni(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 and i!=j){
                    uni.connect(i,j);
                }
            }
        }
        int ans=0;
        for(auto i : uni.size){
            if(i!=0) ans++;
        }
        return ans;
    }
};