class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int tar) {
        int n = arr.size();
        vector<vector<int>>sub_arrs;
        int st = 0, sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            while(sum > tar) sum -= arr[st++];
            if(sum == tar) sub_arrs.push_back({st, i});
        }
        vector<int>dp(n, 1e8);
        int ans = 1e8, idx = -1, min_sub = 1e8;
        for(int i = 0; i < sub_arrs.size(); i++){
            int st = sub_arrs[i][0], ed = sub_arrs[i][1];
            int sub2_len = (ed - st + 1);
            if(idx == -1) idx = ed;
            for(int j = idx; j < ed; j++) dp[j] = min_sub;
            min_sub = min(min_sub, sub2_len);
            dp[ed] = min_sub;
            if(st > 0) ans = min(ans, (dp[st - 1] + sub2_len) );
            idx = ed;
        }
        if(ans >= 1e8) return -1;
        return ans;
    }
};