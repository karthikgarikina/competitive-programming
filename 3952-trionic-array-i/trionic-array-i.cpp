class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        bool l=true,p=false,q=false,r=false;
        for(int i=1;i<n;i++){
            if(!q and nums[i]>nums[i-1]){
                p=true;
            }
            else if(!r and p and nums[i]<nums[i-1]){
                q=true;
            }
            else if(p and q and nums[i]>nums[i-1]){
                r=true;
            }
            else return false;
        }
        return (l and p and q and r);
    }
};