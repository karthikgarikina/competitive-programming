class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int,int>Map;
        for(int i=0;i<n;i++){
            Map[nums1[i]]++;
            Map[nums2[i]]--;
        }
        int ans1=0,ans2=0;

        for(auto i : Map){
            int freq=i.second;
            if(freq%2!=0) return -1;

            if(freq>0) ans1+=(freq/2);
            else ans2+=((-1*freq)/2);
        }
        return min(ans1,ans2);
    }
};