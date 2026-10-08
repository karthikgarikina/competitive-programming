class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int left = 0;
        for(auto ch : s){
            if(left == 0){
                left++;
                continue;
            }
            if(left == 1 and ch == ')'){
                left = 0;
                continue;
            }
            if(ch == '(') left++;
            else left--;
            ans += ch;
        }
        return ans;
    }
};