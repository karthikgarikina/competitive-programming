class Solution:
    def findKthLargest(self, nums, k):
        pq = []
        for num in nums:
            if len(pq)<k:
                heapq.heappush(pq, num)

            elif len(pq) == k and num>pq[0]:
                heapq.heappop(pq)
                heapq.heappush(pq, num)      

        return pq[0]