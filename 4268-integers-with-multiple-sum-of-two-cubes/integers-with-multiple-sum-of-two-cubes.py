from collections import defaultdict

class Solution:
    def findGoodIntegers(self, n: int) -> list[int]:
        Map = defaultdict(int)
        limit = int(n ** (1/3)) + 1
        
        for a in range(1, limit):
            for b in range(a, limit):
                val = a*a*a + b*b*b
                if val > n:
                    break
                Map[val] += 1
        
        ans = []
        for key, val in Map.items():
            if val > 1:
                ans.append(key)
        ans.sort()
        return ans