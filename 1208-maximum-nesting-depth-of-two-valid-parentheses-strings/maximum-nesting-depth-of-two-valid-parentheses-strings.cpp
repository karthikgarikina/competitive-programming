class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int>ans(n);
        int a = 0, b = 0;
        stack<int>forwards;
        for(int i = 0; i < n; i++){
            if(seq[i] == ')'){
                int last = forwards.top();
                forwards.pop();
                ans[i] = last;
                if(last == 0) a--;
                else b--;
                continue;
            }
            if(a < b){
                ans[i] = 0;
                a++, forwards.push(0);
            }
            else{
                ans[i] = 1;
                b++, forwards.push(1);
            }
        }
        return ans;
    }
};