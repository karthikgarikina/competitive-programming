class Solution:
    def nextLargerElement(self, arr):
        n=len(arr)
        stack=list()
        ans=[-1]*n
        for j in range(n-1,-1,-1):
            i=arr[j]
            while len(stack)>0 and stack[-1]<=i:
                stack.pop()
            if len(stack)>0:
                ans[j]=stack[-1]
            else:
                ans[j]=-1
            stack.append(i)    
                
        return ans     
        