class Solution:
    def maxSubarraySum(self, arr, k):
        sum,st,ans=0,0,0
        
        for i in range(len(arr)):
            sum+=arr[i]
            ans=max(ans,sum)
            if (i-st+1)==k:
                sum-=arr[st]
                st+=1
                
        return ans        
                
        