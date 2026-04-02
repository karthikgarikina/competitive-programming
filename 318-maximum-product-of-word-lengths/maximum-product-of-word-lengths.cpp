class Solution {
public:
    bool valid(int i, int j, vector<vector<bool>>&freq){
        for(int idx=0;idx<26;idx++){
            if(freq[i][idx] and freq[j][idx]) return false;
        }
        return true;
    }

    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<vector<bool>>freq(n,vector<bool>(26,false));
        for(int i=0;i<n;i++){
            for(auto ch : words[i]){
                freq[i][ch-'a']=true;
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