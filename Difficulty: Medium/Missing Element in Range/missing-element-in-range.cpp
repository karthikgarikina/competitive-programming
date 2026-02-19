class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_map<int,bool>there;
        vector<int>ans;
        for(auto i : arr) there[i]=true;
        for(int i=low;i<=high;i++){
            if(there.find(i)==there.end()) ans.push_back(i);
        }
        return ans;
    }
};