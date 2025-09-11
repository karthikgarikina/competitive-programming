class Solution {
public:
    int minOperations(string s) {
        int mini=INT_MAX;
        for(auto ch : s){
            if(ch!='a') mini=min(mini,int(ch));
        }
        if(mini==INT_MAX) return 0;
        cout<<mini;
        return 26-(mini-'a');
    }
};