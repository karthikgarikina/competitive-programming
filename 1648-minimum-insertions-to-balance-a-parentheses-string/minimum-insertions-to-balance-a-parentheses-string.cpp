class Solution {
public:
    int minInsertions(string s) {
        int left = 0, right = 0, ans = 0;
        for(auto ch : s){
            if(ch == '('){
                if(right == 1){
                    ans++, right = 0, left--;
                    if(left < 0)
                        left = 0, ans++;
                }
                left++;
            }
            else right++;

            if(right == 2){
                right = 0, left--;
                if(left < 0)
                    left = 0, ans++;
            }
        }
        if(right == 1){
            ans++, right++;
        }
        if(right == 2){
            left--;
        }
        if(left < 0){
            ans++, left = 0;
        }
        ans += (left * 2);
        return ans;
    }
};