class Solution {
public:
    int maxProduct(int n) {
        int maxi1 = 0, maxi2 = 0;
        while(n > 0){
            int dig = n % 10;
            if(dig > maxi1){
                maxi2 = maxi1;
                maxi1 = dig;
            }
            else if(dig > maxi2) maxi2 = dig;
            n /= 10;
        }
        return maxi1 * maxi2;
    }
};