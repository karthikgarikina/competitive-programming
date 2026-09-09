class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long cur = 9, dig = 1;
        long long p10 = 10;
        while(true){
            long long ub = p10 - 1;
            if( ub >= n){
                long long rem = ub - n;
                cur -= rem;
                ans += (((dig - 1) / 3)*cur);
                break;
            }
            ans += (((dig - 1) / 3)*cur);
            dig++;
            p10 *= 10;
            cur *= 10;
        }
        return ans;
    }
};