class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        vector<int>platforms(2361,0);
        int n=arr.size();
        for(int i=0;i<n;i++){
            int st=arr[i],ed=dep[i];
            platforms[st]+=1;
            platforms[ed+1]-=1;
        }
        int ans=platforms[0];
        for(int i=1;i<2361;i++){
            platforms[i]+=platforms[i-1];
            ans=max(ans,platforms[i]);
        }
        return ans;
        
    }
};
