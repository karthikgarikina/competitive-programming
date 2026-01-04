class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto num : nums){
            int sum=0,cnt=0;
            for(int i=1;i*i<=num;i++){
                if(num%i==0){
                    int lhs=i,rhs=(num/i);
                    sum+=i;
                    cnt++;
                    if(lhs!=rhs){
                        sum+=(num/i);
                        cnt++;
                    }
                }
            }
            if(cnt==4){
                ans+=sum;
            }
        }
        return ans;
    }
};