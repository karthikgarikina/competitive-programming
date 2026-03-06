class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag=false;
        for(auto ch : s){
            if(ch=='0') flag=true;
            if(ch=='1' and flag) return false;
        }
        return true;
    }
};