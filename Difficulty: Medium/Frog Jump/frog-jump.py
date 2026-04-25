class Solution:
    def minCost(self, height):
        n=len(height)
        if n==1:
            return 0
        cost=[0]*n
        cost[1]=abs(height[0]-height[1])
        for i in range(2,n):
            cost[i]=min(cost[i-2]+abs(height[i-2]-height[i]),
                        cost[i-1]+abs(height[i-1]-height[i]))
        return cost[n-1]                