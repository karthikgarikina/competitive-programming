class Solution {
  public:
    bool isValid(vector<int>& arr, int k, long long sum){
        long long p=1, curSum=0;
        for(auto i : arr){
            if(i+curSum>sum){
                curSum=i;
                p++;
            }
            else curSum+=i;
        }
        return p<=k;
    }
    int minTime(vector<int>& arr, int k) {
        long long low=*max_element(arr.begin(),arr.end());
        long long high=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isValid(arr,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};