class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>extsp;
        for(auto i : grid) for(auto j : i) extsp.push_back(j);
        sort(extsp.begin(),extsp.end());
        int n=extsp.size(),mid=extsp[n/2],opp=0,mini=extsp[0];
        mid-=mini;
        for(auto i : extsp){
            i-=mini;
            int rem=abs(i-mid);
            if(rem%x!=0){
                opp=-1;
                break;
            }
            opp+=(rem/x);
        }
        return opp;

    }
};