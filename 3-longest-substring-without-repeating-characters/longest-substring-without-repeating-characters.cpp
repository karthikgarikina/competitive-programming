class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool>Map;
        int n=s.size(),st=0,ans=0;
        for(int i=0;i<n;i++){
            if(Map.find(s[i])!=Map.end()){
                while(st<i){
                    Map.erase(s[st]);
                    if(s[st]==s[i]){
                        st++;
                        break;
                    }
                    st++;
                }
                Map[s[i]]=true;
            }
            else{
                Map[s[i]]=true;
            }
            ans=max(ans,i-st+1);
        }
        return ans;
    }
};