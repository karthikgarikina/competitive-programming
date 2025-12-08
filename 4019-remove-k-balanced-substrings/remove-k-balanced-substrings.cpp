class Solution {
public:
    string removeSubstring(string s, int k) {
        stack<pair<char,int>>S;
        for(auto ch : s){
            if(S.empty()){
                S.push({ch,1});
            }
            else if(ch=='('){
                auto last=S.top();
                if(last.first==ch){
                    S.pop();
                    S.push({ch,last.second+1});
                }
                else S.push({ch,1});
            }
            else{
                auto last=S.top();
                if(last.first==ch){
                    S.pop();
                    S.push({ch,last.second+1});
                }
                else S.push({ch,1});

                if(S.size()<2) continue;
                auto last1=S.top();
                S.pop();
                auto last2=S.top();
                S.pop();
                if(min(last1.second,last2.second)==k){
                    int rem=last2.second-k;
                    if(rem!=0) S.push({'(',rem});
                }
                else{
                    S.push(last2),S.push(last1);
                }
            }
        }
        string ans="";
        while(!S.empty()){
            auto last=S.top();
            S.pop();
            int len=last.second;
            char ch=last.first;
            while(len--) ans+=ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};