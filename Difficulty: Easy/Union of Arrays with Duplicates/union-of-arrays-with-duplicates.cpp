class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int>Map;
        vector<int>ans;
        for(auto i : a){
            if(Map.find(i)==Map.end()){
                ans.push_back(i);
                Map[i]++;
            }
        }
        for(auto i : b){
            if(Map.find(i)==Map.end()){
                ans.push_back(i);
                Map[i]++;
            }
        }
        return ans;
    }
};