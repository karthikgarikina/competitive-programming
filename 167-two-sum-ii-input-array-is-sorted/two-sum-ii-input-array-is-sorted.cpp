class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int newTar=(target-nums[i]);
            int low=0, high=n-1;
            if(newTar<nums[i]) high=i-1;
            else low=i+1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(nums[mid]==newTar) return {i+1,mid+1};
                else if(nums[mid]>newTar) high=mid-1;
                else low=mid+1;
            }
        }
        return {-1,-1};
    }
};