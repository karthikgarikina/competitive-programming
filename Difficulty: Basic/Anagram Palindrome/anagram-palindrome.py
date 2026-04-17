from collections import defaultdict
class Solution:
    def canFormPalindrome(self, s):
        # code here
        Map=defaultdict(int)
        for ch in s:
            Map[ch]+=1
        odd=0
        for val in Map.values():
            if val%2!=0:
                odd+=1
                
        if odd>1:
            return False
        return True    