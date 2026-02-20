class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long low=min(a,b);
        long long high=n*low;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long  ad=mid/a,bd=mid/b;
            long long abd=mid/((a*b)/__gcd(a,b));
            long long total=(ad+bd-abd);
            if(total<n) low=mid+1;
            else{
                high=mid-1;
            }


        }
        return (high + 1)%int(1e9+7);
    }
};