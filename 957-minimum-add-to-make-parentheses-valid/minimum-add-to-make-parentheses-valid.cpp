class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size(), left_cnt = 0, right_cnt = 0, left = 0, right = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') left_cnt++;
            else left_cnt--;
            if(left_cnt < 0)
                left++, left_cnt = 0;

            if(s[n - 1 - i] == ')') right_cnt++;
            else right_cnt--;
            if(right_cnt < 0)
                right++, right_cnt = 0;    
        }
        return min(left_cnt + left, right_cnt + right);
    }
};