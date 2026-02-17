class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        int mx = 0;
        for(auto &i : arr) mx = max(mx, i[1]);

        vector<int> pref(mx+2,0);

        for(auto &i : arr){
            pref[i[0]]++;
            pref[i[1]+1]--;
        }

        int ans = 0;
        for(int i=1;i<=mx;i++){
            pref[i] += pref[i-1];
            ans = max(ans, pref[i]);
        }
        return ans;
    }
};
