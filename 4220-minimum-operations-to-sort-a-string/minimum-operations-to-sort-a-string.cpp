class Solution {
public:
    bool check(int st, int end, string str){
        for(int i=st+1;i<=end;i++){
            if(str[i]<str[i-1]) return true;
        }
        return false;
    }
    int minOperations(string s) {
        string t=s;
        int n=s.size();
        if(n==1) return 0;
        if(n==2 and s[0]>s[1]) return -1;
        else if(n==2) return 0;

        int ans=0;
        if(check(0,n-2,s)){
            ans++;
            sort(s.begin(),s.begin()+n-1);
        }
        if(check(1,n-1,s)){
            ans++;
            sort(s.begin()+1,s.begin()+n);
        }
        if(check(0,n-2,s)) ans++;


        int ans2=0;
        if(check(1,n-1,t)){
            ans2++;
            sort(t.begin()+1,t.begin()+n);
        }
        if(check(0,n-2,t)){
            ans2++;
            sort(t.begin(),t.begin()+n-1);
        }
        if(check(1,n-1,t)) ans2++;
        
        return min(ans,ans2);
        
    }
};