class Solution {
  public:
    long long sum(long long n){
        long long ans=0;
        while(n>0){
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }
    int getCount(int n, int d) {
        long long left=1,right=n;
        long long mini=0;
        while(left<=right){
            long long mid=left+(right-left)/2;
            long long diff=abs(mid-sum(mid));
            if(diff<d){
                mini=max(mini,mid);
                left=mid+1;
            }
            else right=mid-1;
        }
        return n-mini;
    }
};