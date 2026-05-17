class Solution {
public:
    bool helper(int idx, vector<int>&arr, vector<bool>&visited){
        if(idx<0 || idx>=arr.size() || visited[idx]) return false;
        if(arr[idx]==0) return true;
        visited[idx]=true;
        if( helper(idx+arr[idx],arr,visited) ) return true;
        if( helper(idx-arr[idx],arr,visited) ) return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>visited(n,false);
        return helper(start,arr,visited);
    }
};