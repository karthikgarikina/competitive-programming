class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n=len(s)
        flag=defaultdict(bool)
        st=0
        ans=0
        for i in range(n):
            if s[i] in flag:
                while s[st]!=s[i]:
                    del flag[s[st]]
                    st+=1
                st+=1
            flag[s[i]]=True
            ans=max(ans,(i-st+1))   

        return ans       


        