class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        string s1even="",s1odd="",s2even="",s2odd="";
        for(int i=0;i<n;i++){
            if(i%2==0){
                s1even+=s1[i];
                s2even+=s2[i];
            }
            else{
                s1odd+=s1[i];
                s2odd+=s2[i];
            }
        }
        sort(s1even.begin(),s1even.end());
        sort(s2even.begin(),s2even.end());
        sort(s1odd.begin(),s1odd.end());
        sort(s2odd.begin(),s2odd.end());
        return (s1even==s2even and s1odd==s2odd);
    }
};