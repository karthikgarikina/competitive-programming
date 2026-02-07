class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1=nums1.size();
        int s2=nums2.size();
        int s=s1+s2;
        int a[s];
        int mid=s/2;
        int i=0,j=0,k=0;
        double ans;
        while(i<s1 && j<s2)
        {
            if(nums1[i]<nums2[j])
            {
                a[k++]=nums1[i++];
            }
            else
            {
                a[k++]=nums2[j++];
            }
            if(k>mid+1)
            {
                break;
            }
        }
        while(i<s1)
        {
            a[k++]=nums1[i++];
            if(k>mid+1)
            {
                break;
            }
        }
         while(j<s2)
        {
            a[k++]=nums2[j++];
            if(k>mid+1)
            {
                break;
            }
        }
        if(s%2!=0)
        {
          ans= a[mid];
          return ans;
        }
        else
        {
          int a1=a[mid];
          int b=a[mid-1];
          ans=(double)(a1+b)/2;
          return ans;
        }
    }
};