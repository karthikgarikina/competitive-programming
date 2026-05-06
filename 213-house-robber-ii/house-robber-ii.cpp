class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int pic=nums[0],notpic=0;
        for(int i=1;i<n-1;i++){
            int npic=notpic+nums[i];
            int nnotpic=max(pic,notpic);
            pic=npic;
            notpic=nnotpic;
        }
        int opp1= max(pic,notpic);
        pic=0,notpic=0;
        for(int i=1;i<n;i++){
            int npic=notpic+nums[i];
            int nnotpic=max(pic,notpic);
            pic=npic;
            notpic=nnotpic;
        }
        int opp2= max(pic,notpic);
        return max(opp1,opp2);
    }
};