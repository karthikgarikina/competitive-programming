class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size(), a = 0, b = 0;
        vector<int>ans(n);
        for(int i = 0; i < n; i++){
            if(seq[i] == ')'){
                if(a > b){
                    ans[i] = 0, a--;
                }
                else{
                    ans[i] = 1, b--;
                }
            }
            else{
                if(a < b){
                    ans[i] = 0, a++;
                }
                else{
                    ans[i] = 1, b++;
                }
            }
        }
        return ans;
    }
};