class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1') pq.push(nums[i]);
            else if(!pq.empty() and pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};