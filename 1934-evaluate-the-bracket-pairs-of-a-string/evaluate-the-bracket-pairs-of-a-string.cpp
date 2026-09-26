class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string>know;
        for(auto i : knowledge){
            know[i[0]] = i[1];
        }
        string ans = "", key = "";
        bool iskey = false;
        for(auto ch : s){
            if(ch == '(') iskey = true;
            else if(ch == ')'){
                if(know.count(key)) ans += know[key];
                else ans += '?';
                key = "";
                iskey = false;
            }
            else if(iskey) key += ch;
            else ans += ch;
        }
        return ans;
    }
};