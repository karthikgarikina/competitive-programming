class Solution {
public:
    bool valid(string &p, int idx){
        while(idx < p.size() - 1){
            if(p[idx + 1] == '*') idx += 2;
            else break;
        }
        return idx == p.size();
    }
    bool check(string &s, int idx1, string &p, int idx2, vector<vector<int>>&dp){
        if(idx1 == s.size() and valid(p, idx2) ) return true;
        if(idx1 == s.size() or idx2 == p.size()) return false;
        // if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(idx2 < p.size() - 1 and p[idx2 + 1] == '*'){
            if( check(s, idx1, p, idx2 + 2, dp) ) return true;
            if(p[idx2] != '.' and p[idx2] != s[idx1]) return false;
            if( check(s, idx1 + 1, p, idx2, dp) ) return true;
        }
        else if(p[idx2] == '.'){
            if( check(s, idx1 + 1, p, idx2 + 1, dp) ) return true;
        }
        else{
            if(p[idx2] != '.' and s[idx1] != p[idx2]) return false;
            if( check(s, idx1 + 1, p, idx2 + 1, dp) ) return true;
        }
        return dp[idx1][idx2] = 0;
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>>dp(m + 2, vector<int>(n + 2, -1));
        return check(s, 0, p, 0, dp);
    }
};