class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=1;
        string ans="";
        ans+=s[0];
        for(int i=0;i<n;i++){
            int l1=i-1,r1=i+1;
            int l2=i,r2=i+1;
            while(l1>=0 and r1<n and s[l1]==s[r1]){
                l1--,r1++;
            }
            l1++,r1--;


            while(l2>=0 and r2<n and s[l2]==s[r2]){
                l2--,r2++;
            }
            l2++,r2--;

            if((r1-l1+1)>maxlen){
                maxlen=(r1-l1+1);
                ans=s.substr(l1,(r1-l1+1));
            }
            if((r2-l2+1)>maxlen){
                maxlen=(r2-l2+1);
                ans=s.substr(l2,(r2-l2+1));
            }
        }
        return ans;
    }
};