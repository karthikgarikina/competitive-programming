class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack=list()
        for ast in asteroids:
            cur=ast
            while len(stack)>0 and stack[-1]>0 and cur<0:
                if stack[-1]==-cur:
                    del stack[-1]
                    cur=None
                    break

                elif stack[-1]<-cur:
                    del stack[-1]

                else:
                    cur=None
                    break

            if cur!=None:
                stack.append(cur)    

        return stack        






        