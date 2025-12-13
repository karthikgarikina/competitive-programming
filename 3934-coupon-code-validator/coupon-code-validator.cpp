class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<vector<string>>ans(4);
        int n=code.size();
        for(int i=0;i<n;i++){
            bool flag=true;
            for(auto ch : code[i]){
                if(ch=='_' || (ch<='z' and ch>='a') || (ch<='Z' and ch>='A') || (ch>='0' and ch<='9')){
                    continue;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(code[i]=="") flag=false;
            if(flag){
                if(businessLine[i]=="electronics"){
                    if(isActive[i]) ans[0].push_back(code[i]);
                }
                else if(businessLine[i]=="grocery"){
                    if(isActive[i]) ans[1].push_back(code[i]);
                }
                else if(businessLine[i]=="pharmacy"){
                    if(isActive[i]) ans[2].push_back(code[i]);
                }
                else if(businessLine[i]=="restaurant"){
                    if(isActive[i]) ans[3].push_back(code[i]);
                }
            }
        }
        for(int i=0;i<4;i++){
            sort(ans[i].begin(),ans[i].end());
        }
        vector<string>res;
        for(int i=0;i<4;i++){
            for(auto str : ans[i]) res.push_back(str);
        }
        return res;
    }
};