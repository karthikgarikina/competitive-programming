class Solution:
    def maxOnes(self, arr):
        # code here
        n=len(arr)
        maxi=0
        cur=0
        st,ed=0,n-1
        for i in range(n):
            if cur<0:
                cur=0
                st=i
            if arr[i]==1:
                cur-=1
            else:
                cur+=1
            if maxi<cur:
                maxi=cur
                ed=i
                
        ans=maxi
        for i in range(n):
            if arr[i]==1:
                ans+=1
                
        return ans        
                
            
        