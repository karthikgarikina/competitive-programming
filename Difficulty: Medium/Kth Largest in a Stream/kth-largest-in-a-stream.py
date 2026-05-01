import heapq
class Solution:
    def kthLargest(self, arr, k):
        # code here 
        pq=list()
        ans=[]
        for i in arr:
            if len(pq)<k:
                heapq.heappush(pq,i)
            elif pq[0]<i:
                heapq.heappop(pq)
                heapq.heappush(pq,i)
                
            if len(pq)<k:
                ans.append(-1)
            else:
                ans.append(pq[0])
        return ans        