class Solution {
public:
    bool hasAlternatingBits(int n) {
        return (long long)((n^(n>>1))==(long long)(1<<(long long)log2(n))+(1<<(long long)log2(n))-1);
    }
};