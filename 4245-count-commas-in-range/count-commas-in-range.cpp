class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        int cur = 9, dig = 1;
        while(true){
            int ub = pow(10, dig) - 1;
            if( ub >= n){
                int rem = ub - n;
                cur -= rem;
                ans += (((dig - 1) / 3)*cur);
                break;
            }
            ans += (((dig - 1) / 3)*cur);
            dig++;
            cur *= 10;
        }
        return ans;
    }
};