class Solution {
  public:
    string minWindow(string &s, string &p) {
        unordered_map<char,int>need,have;
        bool freq[27]={false};
        for(auto ch : p){
            need[ch]++;
            freq[(ch-'a')]=true;
        }
        int n=s.size(),st=0;
        int mini=INT_MAX,start=0,end=n-1;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(freq[(ch-'a')]){
                if(need.find(ch)==need.end()) have[ch]++;
                else need[ch]--;
                if(need[ch]==0) need.erase(ch);
            }
            
            while(need.size()==0){
                if((i-st+1)<mini){
                    mini=(i-st+1);
                    start=st,end=i;
                }
                
                if(freq[(s[st]-'a')] and have.find(s[st])==have.end()) need[s[st]]++;
                else if(freq[(s[st]-'a')]){
                    have[s[st]]--;
                    if(have[s[st]]==0) have.erase(s[st]);
                }
                st++;
                
            }
        }
        
        
        if(mini==INT_MAX) return "";
        string ans="";
        for(int i=start;i<=end;i++) ans+=s[i];
        return ans;
    }
};