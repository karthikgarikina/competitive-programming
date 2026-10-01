class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto b : s){
            if(b == '(' || b == '[' || b == '{') st.push(b);
            else if(b == ')'){
                if(!st.empty() && st.top() == '(') st.pop();
                else return false;
            }
            else if(b == ']'){
                if(!st.empty() && st.top() == '[') st.pop();
                else return false;
            }
            else if(b == '}'){
                if(!st.empty() && st.top() == '{') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};