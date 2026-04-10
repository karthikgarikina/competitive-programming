class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        uniques=defaultdict(list)
        n=len(nums)
        for i in range(n):
            uniques[nums[i]].append(i)

        ans=float('inf')    
        for vals in uniques.values():
            size=len(vals)
            print(vals)
            for i in range(size):
                if i+2>=size:
                    break
                ans=min(ans,2*abs(vals[i]-vals[i+2]))

        if ans==float('inf'):
            return -1        
        return ans              
        