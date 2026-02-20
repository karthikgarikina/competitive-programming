class Solution {
  public:
    static bool comp(const string& a, const string& b){
        return a+b>=b+a;
    }
    string findLargest(vector<int> &arr) {
        vector<string>vals;
        for(auto i : arr) vals.push_back(to_string(i));
        sort(vals.begin(),vals.end(),comp);
        string ans="";
        int n=vals.size();
        for(int i=0;i<n;i++) ans+=vals[i];
        if(ans[0]=='0') return "0";
        return ans;
    }
};