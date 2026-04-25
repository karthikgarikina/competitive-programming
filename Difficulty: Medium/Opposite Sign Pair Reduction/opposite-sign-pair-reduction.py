class Solution:
    def reducePairs(self, arr):
        stack=list()
        for val in arr:
            keep=True
            while len(stack)!=0 and ((stack[-1]>0 and val<0) or (stack[-1]<0 and val>0)):
                if abs(stack[-1])==abs(val):
                    stack.pop()
                    keep=False
                    break
                elif abs(stack[-1])>abs(val):
                    keep=False
                    break
                else:
                    stack.pop()
            if keep:
                stack.append(val)
                
        return stack            