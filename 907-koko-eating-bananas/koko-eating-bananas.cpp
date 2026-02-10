class Solution {
public:
    bool check(vector<int>&piles, int k, int h){
        long long total=0;
        for(auto i : piles){
            total+=(i+k-1)/k;
        }
        return total<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=1;
        for(auto i : piles) high=max(high,i);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool flag=check(piles,mid,h);
            if(flag){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};