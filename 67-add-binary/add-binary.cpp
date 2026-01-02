class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0,j=0,n=a.size(),m=b.size();
        int cnt=0;
        while(i<n and j<m){
            if(a[i]=='1') cnt++;
            if(b[j]=='1') cnt++;

            if(cnt==0) ans+='0';
            else if(cnt==1){
                ans+='1';
                cnt=0;
            }
            else if(cnt==2){
                ans+='0';
                cnt=1;
            }
            else{
                ans+='1';
                cnt=1;
            }

            i++,j++;
        }

        while(j<m){
            if(b[j]=='1') cnt++;

            if(cnt==0) ans+='0';
            else if(cnt==1){
                ans+='1';
                cnt=0;
            }
            else if(cnt==2){
                ans+='0';
                cnt=1;
            }
            else{
                ans+='1';
                cnt=1;
            }
            j++;
        }

        while(i<n){
            if(a[i]=='1') cnt++;

            if(cnt==0) ans+='0';
            else if(cnt==1){
                ans+='1';
                cnt=0;
            }
            else if(cnt==2){
                ans+='0';
                cnt=1;
            }
            else{
                ans+='1';
                cnt=1;
            }
            i++;
        }
        if(cnt!=0) ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;

    }
};