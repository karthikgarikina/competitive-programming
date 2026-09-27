class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<string>st;
        string ans = "";
        for(auto ch : s){
            if(ch == '('){
                st.push("");
            }
            else if(ch == ')'){
                string top = st.top();
                st.pop();
                reverse(top.begin(), top.end());
                if(!st.empty()){
                    string cur = st.top();
                    st.pop();
                    cur += top;
                    st.push(cur);
                }
                else ans += top;
            }
            else if(!st.empty()){
                string top = st.top();
                st.pop();
                top += ch;
                st.push(top);
            }
            else ans += ch;
        }
        return ans;
    }
};