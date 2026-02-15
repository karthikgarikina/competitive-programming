class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        int ans=INT_MAX;
        int n=a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<=n-m;i++){
            ans=min(ans,abs(a[i]-a[i+m-1]));
        }
        return ans;
    }
};