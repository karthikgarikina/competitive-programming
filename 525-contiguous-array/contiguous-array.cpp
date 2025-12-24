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
                if(Map.find({0,diff})==Map.end()){
                    Map[{0,diff}]=zero;
                    cout<<"0,"<<diff<<" "<<zero<<"\n";
                }
            }
            else{
                auto pair={diff,0};
                if(Map.find(pair)!=Map.end()){
                    int val=one-Map[pair];
                    ans=max(ans,2*val);
                }
                if(Map.find({diff,0})==Map.end()){
                    Map[{diff,0}]=one;
                    cout<<diff<<",0"<<" "<<one<<"\n";
                }
            }
        }
        return ans;
    }
};