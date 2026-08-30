class Solution {
public:
    long long MOD = 1e9 + 7;
    long long my_pow(long long base, long long exp){
        if(exp == 0) return 1;
        long long ans = 1;
        while(exp > 1){
            if(exp % 2 == 1){
                ans = (ans * base) % MOD;
                exp--;
            }
            if(exp % 2 == 0){
                base = (base * base) % MOD;
                exp /= 2;
            }
        }
        ans = (ans * base) % MOD;
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for(auto num : nums){
            long long w = (num % 10), d = (num / 10);
            string number = to_string(d);
            long long x = 0, y = 0;
            for(int i = 0; i < number.size(); i++){
                if(i < w) x = ((x * 10) + (number[i] - '0'));
                else y = ((y * 10) + (number[i] - '0'));
            }
            long long decode = my_pow(x, y);
            ans = (ans + decode) % MOD;
        }
        return (int)ans;
    }
};