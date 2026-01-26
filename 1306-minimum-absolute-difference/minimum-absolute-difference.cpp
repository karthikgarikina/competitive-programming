class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size(),mini=abs(arr[0]-arr[1]);
        vector<vector<int>>ans;
        for(int i=0;i<n-1;i++){
            int minDif=abs(arr[i]-arr[i+1]);
            if(minDif==mini) ans.push_back({arr[i],arr[i+1]});
            else if(minDif<mini){
                ans.clear();
                mini=minDif;
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};