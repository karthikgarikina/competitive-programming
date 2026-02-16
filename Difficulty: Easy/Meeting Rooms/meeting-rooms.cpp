class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(),arr.end());
        int ed=arr[0][1];
        int n=arr.size();
        for(int i=1;i<n;i++){
            int nextst=arr[i][0],nexted=arr[i][1];
            if(ed<=nextst) ed=nexted;
            else return false;
            
        }
        return true;
    }
};