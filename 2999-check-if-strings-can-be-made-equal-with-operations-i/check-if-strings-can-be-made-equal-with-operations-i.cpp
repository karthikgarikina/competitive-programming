class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1[0]!=s2[0] and s1[2]==s2[0]){
            swap(s1[0],s1[2]);
        }
        else if(s1[0]!=s2[0]) return false;

        if(s1[1]!=s2[1] and s1[3]==s2[1]){
            swap(s1[1],s1[3]);
        }
        else if(s1[1]!=s2[1]) return false;

        return (s1[2]==s2[2] and s1[3]==s2[3]);
    }
};