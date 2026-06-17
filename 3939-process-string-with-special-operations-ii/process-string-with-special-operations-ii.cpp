class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        long long total=0;
        for(char ch : s){
            if(ch=='#') total*=2;
            else if(ch=='*' and total>0) total--;
            else if(ch>='a' and ch<='z') total++;
        }
        if(k>=total) return '.';
        for(int i=n-1;i>=0;i--){
            if(s[i]=='*') total++;
            else if(s[i]=='%') k = total - k - 1;
            else if(s[i]=='#'){
                total /= 2;
                if(k >= total) k -= total;
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                total--;
                if(k == total) return s[i];
            } 
        }
        return '.';
    }   
};