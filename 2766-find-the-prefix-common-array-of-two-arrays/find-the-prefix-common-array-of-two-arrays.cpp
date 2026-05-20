class Solution {
public:
    int getMatch(vector<int>&freq){
        int cnt=0;
        for(auto i : freq){
            if(i==2) cnt++;
        }
        return cnt;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>freq(n+1,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            freq[A[i]]++;
            freq[B[i]]++;
            ans.push_back(getMatch(freq));
        }
        return ans;
    }
};