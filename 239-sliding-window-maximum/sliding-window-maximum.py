class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans=[]
        dq=deque()
        st=0
        for i in range(len(nums)):
            while len(dq)!=0 and dq[-1]<nums[i]:
                dq.pop()
            dq.append(nums[i])
            if (i-st+1)==k:
                ans.append(dq[0])
                if dq[0]==nums[st]:
                    dq.popleft()
                st+=1   

        return ans                