class Solution:
    def longestPalindrome(self, s: str) -> int:
        Map=defaultdict(int)
        for i in s:
            Map[i]+=1
        oddcnt=0
        for key,val in Map.items():
            if val%2!=0:
                oddcnt+=1
        ans=len(s)
        if oddcnt>0:
            ans-=(oddcnt-1)   
        return ans             

        