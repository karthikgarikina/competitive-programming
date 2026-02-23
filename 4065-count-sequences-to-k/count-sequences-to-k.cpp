class Solution {
public:
    bool flag=false;
    vector<int> findFactor(long long n){
        int a=0,b=0,c=0;
        while(n%2==0 and n>0){
            a++;
            n/=2;
        }
        while(n%3==0 and n>0){
            b++;
            n/=3;
        }
        while(n%5==0 and n>0){
            c++;
            n/=5;
        }
        if(n!=1) flag=true;
        return {a,b,c};
    }
    int checkAll(vector<int>&nums, int idx, int n,vector<map<vector<int>,int>>&dp, vector<int>&curnt, vector<int>&target){
        if(idx>=n){
            if(curnt==target) return 1;
            return 0;
        }
        if(dp[idx].find(curnt)!=dp[idx].end()){
            return dp[idx][curnt];
        }
        vector<int>vals=findFactor(nums[idx]);
        int cnt=0;

        cnt+=checkAll(nums,idx+1,n,dp,curnt,target);
        curnt[0]+=vals[0],curnt[1]+=vals[1],curnt[2]+=vals[2];
        cnt+=checkAll(nums,idx+1,n,dp,curnt,target);
        curnt[0]-=2*vals[0],curnt[1]-=2*vals[1],curnt[2]-=2*vals[2];
        cnt+=checkAll(nums,idx+1,n,dp,curnt,target);
        curnt[0] += vals[0],curnt[1] += vals[1],curnt[2] += vals[2];
        dp[idx][curnt]=cnt;
        return cnt;
    }
    int countSequences(vector<int>& nums, long long k) {
        int n=nums.size();
        vector<map<vector<int>,int>>dp(n);
        vector<int>target=findFactor(k);
        vector<int>curnt={0,0,0};
        if(flag) return 0;
        return checkAll(nums,0,n,dp,curnt,target);
    }
};