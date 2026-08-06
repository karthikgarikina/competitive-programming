class Solution {
public:
    bool check(int n, int t){
        int p = 1;
        while(n > 0){
            p *= (n % 10);
            n /= 10;
        }
        return (p % t == 0);
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(check(n,t)) return n;
            n++;
        }
        return -1;
    }
};