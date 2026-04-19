class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        ans=0
        i,j=0,0
        n,m=len(nums1),len(nums2)
        while i<n and j<m:
            if nums1[i]<=nums2[j]:
                ans=max(ans,j-i)
                j+=1
            elif i==j:
                i+=1
                j+=1
            else:
                i+=1

        return ans                

        