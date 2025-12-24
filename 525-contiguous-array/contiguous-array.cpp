class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<vector<int>,int>Map;
        int one=0,zero=0,ans=0;
        for(auto i : nums){
            if(i==1) one++;
            else zero++;
            int diff=abs(one-zero);

            if(diff==0){
                ans=max(ans,2*one);
            }
            else if(one>zero){
                auto pair={0,diff};
                if(Map.find(pair)!=Map.end()){
                    int val=zero-Map[pair];
                    ans=max(ans,2*val);
                }
                if(Map.find(pair)==Map.end()){
                    Map[pair]=zero;
                }
            }
            else{
                auto pair={diff,0};
                if(Map.find(pair)!=Map.end()){
                    int val=one-Map[pair];
                    ans=max(ans,2*val);
                }
                if(Map.find(pair)==Map.end()){
                    Map[pair]=one;
                }
            }
        }
        return ans;
    }
};