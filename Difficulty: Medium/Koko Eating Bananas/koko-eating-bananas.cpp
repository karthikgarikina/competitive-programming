class Solution {
  public:
    bool canEat(vector<int>&arr, int h, int k){
        long long total=0;
        for(auto i : arr) total+=(i+h-1)/h;
        return total<=k;
    }
    int kokoEat(vector<int>& arr, int k) {
        int low=1, high=*max_element(arr.begin(),arr.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool isCan=canEat(arr,mid,k);
            if(isCan){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};