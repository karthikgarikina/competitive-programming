class Solution {
public:
    string removeSubstring(string str, int k) {
        int left=0,right=0;
        string ans="";
        string s=str;
        int limit=2;
        while(limit--){
            int n=s.size(),idx=-1;
            for(int i=0;i<n;i++){
                if(s[i]=='(') break;
                ans+=')';
                idx=i;
            }
            for(int i=idx+1;i<n;i++){
                if(s[i]=='('){
                    if(right!=0){
                        while(left>0){
                            ans+='(';
                            left--;
                        }
                        while(right>0){
                            ans+=')';
                            right--;
                        }
                    }
                    left++;
                }
                else{
                    right++;
                    if(min(left,right)==k){
                        left-=k;
                        right-=k;
                    }
                }
            }
            while(left>0){
                ans+='(';
                left--;
            }
            while(right>0){
                ans+=')';
                right--;
            }
            s=ans;
            ans="";
        }
        return s;
    }
};