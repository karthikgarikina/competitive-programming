class Solution {
public:
    int binaryGap(int n) {
        int ans=0,cnt=0;
        for(int i=31;i>=0;i--){
            if(n&(1<<i)){
                ans=max(ans,cnt);
                cnt=1;
            }
            else if(cnt!=0) cnt++;
        }
        return ans;
    }
};