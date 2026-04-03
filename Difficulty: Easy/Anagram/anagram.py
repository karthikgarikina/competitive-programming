class Solution:
    def areAnagrams(self, s1, s2):
        freq=[0]*26
        for ch in s1:
            freq[ord(ch)-ord('a')]+=1
        for ch in s2:
            freq[ord(ch)-ord('a')]-=1   
            
        for i in freq:
            if i!=0:
                return False
        return True        
       