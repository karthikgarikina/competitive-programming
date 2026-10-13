class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) nums[i]=nums[i]*-1;
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            ans+=(nums[j]*nums[j]);
            ans-=(nums[i]*nums[i]);
            j--;
            i++;
        }
        if(i==j) ans+=(nums[i]*nums[i]);
        return ans;
    }
};