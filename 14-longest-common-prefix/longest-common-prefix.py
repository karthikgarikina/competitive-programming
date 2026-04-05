class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        first=strs[0]
        last=strs[-1]
        i=0
        size=min(len(first),len(last))
        while i<size and first[i]==last[i]:
            i+=1
        if i==0:
            return ""
        return first[0:i:1]        