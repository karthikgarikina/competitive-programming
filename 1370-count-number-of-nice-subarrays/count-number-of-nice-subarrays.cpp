class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size(), st=0, cnt=0, sub=1, ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2) cnt++;
            if(cnt>k){
                sub=1;
                st++;
                while(nums[st]%2==0){
                    sub++;
                    st++;
                }
                cnt--;
            }
            while(cnt==k and nums[st]%2==0){
                st++;
                sub++;
            }
            if(cnt==k) ans+=sub;
        }
        return ans;
    }
};