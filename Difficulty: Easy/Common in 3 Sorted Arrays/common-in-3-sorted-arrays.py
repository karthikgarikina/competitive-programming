class Solution:
    def commonElements(self, a, b, c):
        ans=[]
        i,j,k=0,0,0
        n,m,o=len(a),len(b),len(c)
        while(i<n and j<m and k<o):
            while(j<m-1 and b[j+1]<=a[i]):
                j+=1
            while(k<o-1 and c[k+1]<=a[i]):
                k+=1    
            if a[i]==b[j] and b[j]==c[k]:
                if len(ans)>0 and ans[-1]==a[i]:
                    i+=1
                    continue
                ans.append(a[i])
            i+=1
        return ans    