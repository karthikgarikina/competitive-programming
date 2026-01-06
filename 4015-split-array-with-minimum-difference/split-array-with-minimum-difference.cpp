class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        long long leftSum=nums[i],rightSum=nums[j];
        for(int idx=1;idx<n;idx++){
            if(nums[idx]>nums[idx-1]){
                i=idx;
                leftSum+=nums[idx];
            }
            else break;
        }
        for(int idx=n-2;idx>=0;idx--){
            if(nums[idx]>nums[idx+1]){
                j=idx;
                rightSum+=nums[idx];
            }
            else break;
        }

        
        if(i+1==j) return abs(leftSum-rightSum);
        else if(i==j){
            return min( abs( (leftSum-nums[i]) - rightSum ), abs( leftSum - (rightSum-nums[i]) ) );
        } 
        return -1;

    }
};