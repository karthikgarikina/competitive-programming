class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        int flag=1;
        for(auto i : nums){
            flag=0;
            for(int j=1;j<=i;j++){
                if(((j)|(j+1))==i){
                    flag=1;
                    ans.push_back(j);
                    break;
                }
            }
            if(flag==0) ans.push_back(-1);
        }
        return ans;
        
    }
};