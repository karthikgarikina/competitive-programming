class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(auto ch : n){
            maxi=max(maxi,(ch-'0'));
        }
        return maxi;
    }
};