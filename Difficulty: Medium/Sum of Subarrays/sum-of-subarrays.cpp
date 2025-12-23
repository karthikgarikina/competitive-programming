class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int n=arr.size(),ans=0,prev=0;
        for(int i=0;i<n;i++){
            prev=((prev-i)+(n-i));
            ans+=prev*arr[i];
        }
        return ans;
        
    }
};