class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size(), left_cnt = 0, left = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') left_cnt++;
            else if(left_cnt > 0) left_cnt--;
            else left++;  
        }
        return (left_cnt + left);
    }
};