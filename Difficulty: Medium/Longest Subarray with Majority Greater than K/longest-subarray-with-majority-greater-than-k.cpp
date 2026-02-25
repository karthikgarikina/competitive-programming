class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n=arr.size(),cnt=0;
        int ans=0;
        unordered_map<int,int>Map;
        for(int i=0;i<n;i++){
            if(arr[i]>k) cnt++;
            else cnt--;
            
            if(cnt>0) ans=i+1;
            else{
                if(Map.find(cnt-1)!=Map.end()){
                    ans=max(ans,i-Map[cnt-1]);
                }
            }
            if(cnt<0 and Map.find(cnt)==Map.end()) Map[cnt]=i;
        }
        return ans;
    }
};