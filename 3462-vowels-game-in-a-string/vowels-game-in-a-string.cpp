class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels=0;
        for(auto ch : s){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') vowels++;
        }
        return vowels!=0;
    }
};