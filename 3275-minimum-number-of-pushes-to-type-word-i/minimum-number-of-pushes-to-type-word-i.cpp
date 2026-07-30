class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0, cnt = 1;
        while(n > 0){
            if(n < 8){
                ans += (n * cnt);
                n = 0;
            }
            else{
                ans += (8 * cnt);
                n -= 8;
            }
            cnt++;
        }
        return ans;
    }
};