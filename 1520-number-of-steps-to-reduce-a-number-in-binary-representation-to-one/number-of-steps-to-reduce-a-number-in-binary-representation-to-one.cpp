class Solution {
public:
    int numSteps(string s) {
        int n=s.size(), c=0, ans=0;
        for(int i=n-1;i>=1;i--){
            if(s[i]=='1') c++;
            if(c==0) ans++;
            else if(c==1){
                ans+=2;
            }
            else if(c==2){
                ans+=1;
                c=1;
            }
        }
        ans+=c;
        return ans;
    }
};