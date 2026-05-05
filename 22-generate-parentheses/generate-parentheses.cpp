class Solution {
public:
    void helper(int l, int r, string& str, vector<string>&ans){
        if(l==0 and r==0){
            ans.push_back(str);
        }
        if(l>0){
            str+="(";
            helper(l-1,r,str,ans);
            str.pop_back();
        }
        if(r>0 and r>l){
            str+=")";
            helper(l,r-1,str,ans);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int l=n,r=n;
        string ds="";
        vector<string>ans;
        helper(l,r,ds,ans);
        return ans;
    }
};