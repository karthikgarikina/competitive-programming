class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<int>>palms;
        for(int i = 0; i < n; i++){

            int l = i, r = i;
            while(l >= 0 and r < n){
                if(s[l] != s[r]) break;
                int len = (r - l + 1);
                if(len >= k){
                    palms.push_back({l, r});
                    break;
                }
                l--, r++;
            }

            l = i, r = i + 1;
            while(l >= 0 and r < n){
                if(s[l] != s[r]) break;
                int len = (r - l + 1);
                if(len >= k){
                    palms.push_back({l, r});
                    break;
                }
                l--, r++;
            }

        }

        sort(palms.begin(), palms.end());
        int ans = 0, bound = -1;
        for(auto i : palms){
            int l = i[0], r = i[1];
            if(l > bound){
                ans++;
                bound = r;
            }
        }
        return ans;
    }
};