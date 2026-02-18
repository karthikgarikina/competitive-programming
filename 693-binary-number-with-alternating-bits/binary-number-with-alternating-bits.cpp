class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long s=log2(n);
        long long total=(long long)(1<<s)+(1<<s)-1;
        return ((n^(n>>1))==total);
    }
};