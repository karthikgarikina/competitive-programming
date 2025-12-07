class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<set<int>>freq(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            int ch=(s[i]-'a');
            freq[ch].insert(i);
        }
        int ans=0;
        for(auto word : words){
            int idx=-1;
            bool flag=true;
            for(char i : word){
                int ch=(i-'a');
                auto it=freq[ch].begin();
                if(idx!=-1){
                    it=freq[ch].upper_bound(idx);
                }

                if(it==freq[ch].end()){
                    flag=false;
                    break;
                }
                else{
                    idx=*it;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};