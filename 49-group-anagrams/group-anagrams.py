
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        Map=defaultdict(list)
        for word in strs:
            freq=[0]*26
            for ch in word:
                freq[ord(ch)-ord('a')]+=1

            key=tuple(freq)    
            Map[key].append(word)

        return list(Map.values())            
