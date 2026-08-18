class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,set<int>>Map;
        int n=nums.size(),maxi=-1;
        if(n<k) return -1;
        for(int i=0;i<=n-k;i++){
            for(int j=i;j<i+k;j++){
                Map[nums[j]].insert(i);
            }
        }
        for(auto i : Map){
            if(i.second.size()==1) 
            {
                cout<<i.first<<" ";
                maxi=max(maxi,i.first);
            }
        }
        return maxi;
    }
};