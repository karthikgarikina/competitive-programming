class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans=list()
        for word in queries:
            for dic in dictionary:
                cnt=0
                for i,j in zip(word,dic):
                    if i!=j:
                        cnt+=1
                if cnt<=2:
                    ans.append(word)
                    break
        return ans                    

        