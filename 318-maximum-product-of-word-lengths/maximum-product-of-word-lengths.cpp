class Solution {
public:
    bool valid(int i, int j, vector<vector<int>>&freq){
        for(int idx=0;idx<26;idx++){
            if(freq[i][idx]!=0 and freq[j][idx]!=0) return false;
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>freq(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(auto ch : words[i]){
                freq[i][ch-'a']++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(valid(i,j,freq)){
                    int profit=words[i].size()*words[j].size();
                    ans=max(ans,profit);
                }
            }
        }
        return ans;
    }
};