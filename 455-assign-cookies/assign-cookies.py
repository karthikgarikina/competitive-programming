class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        s.sort(reverse=True)
        g.sort(reverse=True)
        n=len(s)
        m=len(g)
        i=0
        j=0
        ans=0
        while(i<n and j<m):
            if s[i]>=g[j]:
                ans+=1
                i+=1
                j+=1
            else:
                j+=1
        return ans            
        