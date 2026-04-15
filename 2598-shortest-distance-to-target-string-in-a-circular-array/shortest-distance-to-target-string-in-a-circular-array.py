class Solution:
    def closestTarget(self, words: List[str], target: str, s: int) -> int:
        n=len(words)
        idx,right,left=s,-1,-1
        for i in range(n):
            if words[idx]==target:
                right=i
                break
            idx+=1
            idx=idx%n
        idx=s
        for i in range(n):
            if words[idx]==target:
                left=i
                break
            idx-=1
            if idx<0:
                idx=n-1

        return min(left,right)      






