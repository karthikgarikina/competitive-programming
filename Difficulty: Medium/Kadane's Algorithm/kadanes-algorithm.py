class Solution:
    def maxSubarraySum(self, arr):
        cursum=0
        maxsum=float('-inf')
        for i in arr:
            cursum+=i
            maxsum=max(maxsum,cursum)    
            if cursum<0:
                cursum=0
        return maxsum            