class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        Map=defaultdict(int)
        ans=float('inf')
        for idx,val in enumerate(nums):
            if val in Map:
                ans=min(ans,abs(idx-Map[val]))
            string=str(val)
            string=string[::-1]
            Map[int(string)]=idx

        if ans==float('inf'):
            return -1
        return ans          
             