class Solution {
public:
    char give(int idx, vector<int>&letters){
        if(idx>=26) return '1';
        for(int i=idx;i<26;i++){
            if(letters[i]>=1){
                letters[i]--;
                return ('a'+i);
            }
        }
        return '1';
    }
    void find(int i, int j, string& ans, string& target, vector<int>&letters, int add){
        if(i<0 or i>j) return;
        if(i==j) add=1;
        char ch=give(target[i]-'a'+add,letters);
        if(ch=='1'){
            if(i==0) return;
            else{
                int val=ans[ans.size()-1]-'a';
                ans.erase(ans.size()-1);
                letters[val]++;
                find(i-1,j,ans,target,letters,1);
            }
        }
        else if(ch==target[i]){
            ans+=ch;
            find(i+1,j,ans,target,letters,0);
        }
        else{
            ans+=ch;
            for(int i=0;i<26;i++){
                while(letters[i]--){
                    ans+=('a'+i);
                }
            }
            return;
        }
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int>letters(26,0);
        for(auto i : s) letters[i-'a']++;
        string ans="";
        int n=s.size();
        int i=0,j=n-1;
        find(i,j,ans,target,letters,0);
        return ans;
    }
};