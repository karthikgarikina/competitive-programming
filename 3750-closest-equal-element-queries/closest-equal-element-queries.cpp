class Solution {
public:
    int findIdx(vector<int>&arr, int key){
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==key) return mid;

            if(arr[mid]>key){
                high=mid-1;
            }
            else low=mid+1;
        }
        return -1;
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>Map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(Map.find(nums[i])==Map.end()){
                Map[nums[i]]={i};
            }
            else{
                Map[nums[i]].push_back(i);
            }
        }
        vector<int>ans;
        for(auto i : queries){
            int val=nums[i];
            auto& arr=Map[val];
            if(arr.size()==1){
                ans.push_back(-1);
                continue;
            }
            int idx=findIdx(arr,i);
            int len=arr.size();

            int leftIdx = (idx - 1 + len) % len;
            int rightIdx = (idx + 1) % len;
            int left = arr[leftIdx];
            int right = arr[rightIdx];
            int d1 = abs(i - left);
            int d2 = abs(i - right);
            int distLeft = min(d1, n - d1);
            int distRight = min(d2, n - d2);
            ans.push_back(min(distLeft, distRight));  
        }
        return ans;
    }
};