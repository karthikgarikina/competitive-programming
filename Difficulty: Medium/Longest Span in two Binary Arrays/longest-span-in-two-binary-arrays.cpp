class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        unordered_map<int,int>Map;
        int n=a1.size();
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(a1[i]==1) cnt++;
            if(a2[i]==1) cnt--;
            
            if(cnt==0) ans=max(ans,i+1);
            else{
                if(Map.find(cnt)==Map.end()) Map[cnt]=i;
                ans=max(ans,{i-Map[cnt]});
            }
        }
        return ans;
    }
};