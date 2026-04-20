class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        ans=0
        n=len(colors)
        for i in range(n-1,0,-1):
            if colors[0]!=colors[i]:
                ans=i
                break
        for i in range(0,n-1):
            if colors[n-1]!=colors[i]:
                ans=max(n-i-1,ans)
                break
        return ans        

        