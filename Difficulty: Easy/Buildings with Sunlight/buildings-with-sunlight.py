class Solution:
    def visibleBuildings(self, arr):
        # code here
        maxi,ans=0,0
        for h in arr:
            if h>=maxi:
                ans+=1
                maxi=h
        return ans        