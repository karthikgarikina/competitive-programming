class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int i = 0, j = strs.size() - 1, idx = 0;
        string ans = "";
        if(i == j) return strs[i];
        while(idx < strs[i].size() and idx < strs[j].size() and strs[i][idx] == strs[j][idx]) ans += strs[i][idx], idx++;
        return ans;
    }
};