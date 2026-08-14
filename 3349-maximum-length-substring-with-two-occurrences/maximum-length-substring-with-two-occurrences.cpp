class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {0};
        int n = s.size(), st = 0, ans = 0;
        for(int i = 0; i < n; i++){
            int cur = (s[i] - 'a');
            freq[cur]++;
            while(freq[cur] > 2) freq[(s[st++] - 'a')]--;
            ans = max(ans, (i - st + 1));
        }
        return ans;
    }
};