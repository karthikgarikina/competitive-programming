class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto b : s){
            if(b == '(' || b == '[' || b == '{') st.push(b);
            else{
                if(st.empty()) return false;
                if( (st.top() == '(' and b == ')') or (st.top() == '[' and b == ']') or (st.top() == '{' and b == '}') )
                    st.pop();
                else return false;    
            }
        }
        return st.empty();
    }
};