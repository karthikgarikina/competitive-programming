class Solution {
public:
    bool recursion(int l, int r, int tar, vector<int>&nums){
        if(l>r) return false;
        int mid=(l+r)/2;
        int l2=max(l,mid-1),r2=min(r,mid+1);
        if(tar==nums[mid]){
            return true;
        }
        bool flag1=false,flag2=false;
        if(nums[l]<=nums[l2]) flag1=true;
        if(nums[r]>=nums[r2]) flag2=true;

        if((flag1 and flag2) or (!flag1 and !flag2)){
            if(recursion(l,mid-1,tar,nums)) return true;
            if(recursion(mid+1,r,tar,nums)) return true;
        }

        if(nums[l]<=nums[l2]){
            if(tar>=nums[l] and tar<=nums[l2]){
                if(recursion(l,mid-1,tar,nums)) return true;
            }
            else{
                if(recursion(mid+1,r,tar,nums)) return true;
            }
        }
        else if(nums[r]>=nums[r2]){
            if(tar>=nums[r2] and tar<=nums[r]){
                if(recursion(mid+1,r,tar,nums)) return true;
            }
            else{
                if(recursion(l,mid-1,tar,nums)) return true;
            }
        }
        return false;

    }
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        return recursion(l,r,target,nums);
    }
};