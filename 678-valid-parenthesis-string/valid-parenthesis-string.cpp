class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), left_cnt = 0, right_cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' or s[i] == '*') left_cnt++;
            else left_cnt--;

            if(s[n - 1 - i] == ')' or s[n - 1 - i] == '*') right_cnt++;
            else right_cnt--;

            if(left_cnt < 0 or right_cnt < 0) return false;
        }
        return true;
    }
};