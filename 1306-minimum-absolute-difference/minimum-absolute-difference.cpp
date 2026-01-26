class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int mini=abs(arr[0]-arr[1]);
        for(int i=1;i<arr.size()-1;i++){
            int minDif=abs(arr[i]-arr[i+1]);
            if(minDif<mini){
                mini=minDif;
            }
        }
        for(int i=0;i<arr.size()-1;i++){
            int minDif=abs(arr[i]-arr[i+1]);
            if(minDif==mini) ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};