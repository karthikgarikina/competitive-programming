class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            unordered_map<int,int>Map;
            for(int j=i;j<n;j++){
                Map[s[j]]++;
                int temp=Map[s[j]];
                bool flag=true;
                for(auto i : Map){
                    if(i.second!=temp){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    ans=max(ans,(j-i+1));
                }
                
            }
        }
        return ans;
    }
};