class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            int l2=max(l,mid-1),r2=min(r,mid+1);
            cout<<l<<" "<<mid<<" "<<r<<"\n";
            if(target==nums[mid]){
                ans=mid;
                break;
            }
            else if(nums[l]<=nums[l2]){
                if(target>=nums[l] and target<=nums[l2]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(target>=nums[r2] and target<=nums[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return ans;
    }
};