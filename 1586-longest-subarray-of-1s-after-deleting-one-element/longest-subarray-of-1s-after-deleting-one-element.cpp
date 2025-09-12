class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool flag=false;
        int first=0,second=0,zero=0;
        int ans=INT_MIN;
        for(auto i : nums){
            if(i==0){
                flag=true;
                ans=max(first+second,ans);
                second=first;
                first=0;
                zero++;
                if(zero>1) first=0,second=0;
            }
            else{
                zero=0;
                first++;
            }
        }
        ans=max(ans,first+second);
        if(!flag) ans--;
        if(ans<0) return 0; 
        return ans;
    }
};