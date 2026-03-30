class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        vector<int>s1even(26,0),s2even(26,0),s1odd(26,0),s2odd(26,0);
        for(int i=0;i<n;i++){
            if(i%2==0){
                s1even[s1[i]-'a']++;
                s2even[s2[i]-'a']++;
            }
            else{
                s1odd[s1[i]-'a']++;
                s2odd[s2[i]-'a']++;
            }
        }
        return (s1even==s2even and s1odd==s2odd);
    }
};