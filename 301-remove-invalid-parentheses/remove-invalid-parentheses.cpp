class Solution {
public:
    unordered_set<string>ans;
    bool isValid(string& str){
        int left = 0, right = 0;
        for(auto ch : str){
            if(ch == '(') left++;
            else if(ch == ')'){
                if(left > 0) left--;
                else right++;
            }
        }
        return (left == 0 and right == 0);
    }
    void helper(int idx, string& s, string& cur, int left, int right){
        if(idx == s.size()){
            if(left == 0 and right == 0 and isValid(cur)) ans.insert(cur);
            return;
        }
        if(s[idx] == '('){
            if(left > 0) helper(idx + 1, s, cur, left - 1, right);
            cur.push_back(s[idx]);
            helper(idx + 1, s, cur, left, right);
            cur.pop_back();
        }
        else if(s[idx] == ')'){
            if(right > 0) helper(idx + 1, s, cur, left, right - 1);
            cur.push_back(s[idx]);
            helper(idx + 1, s, cur, left, right);
            cur.pop_back();
        }
        else{
            cur.push_back(s[idx]);
            helper(idx + 1, s, cur, left, right);
            cur.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for(auto ch : s){
            if(ch == '(') left++;
            else if(ch == ')'){
                if(left > 0) left--;
                else right++;
            }
        }
        string cur = "";
        helper(0, s, cur, left, right);
        vector<string>res;
        for(auto i : ans) res.push_back(i);
        return res;
    }
};