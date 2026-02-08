class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        deque<long long>mini,maxi;
        long long ans=0;
        int st=0;
        for(int i=0;i<n;i++){
            while(!mini.empty() and mini.back()>nums[i]) mini.pop_back();
            mini.push_back(nums[i]);
            while(!maxi.empty() and maxi.back()<nums[i]) maxi.pop_back();
            maxi.push_back(nums[i]);

            long long cost=abs(maxi.front()-mini.front())*(i-st+1);
            while(cost>k){
                if(mini.front()==nums[st]) mini.pop_front();
                if(maxi.front()==nums[st]) maxi.pop_front();
                st++;
                cost=abs(maxi.front()-mini.front())*(i-st+1);
            }
            ans+=(i-st+1);
        }
        return ans;
    }
};