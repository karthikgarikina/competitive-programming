class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        unordered_map<char,vector<int>>Map;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                if(Map.find(ch)==Map.end()){
                    Map[ch]={i};
                }
                else{
                    Map[ch].push_back(i);
                }
            }
        }
        vector<pair<char,int>>vowels;
        for(auto i : Map){
            vowels.push_back({i.first,i.second.size()});
        }
        sort(vowels.begin(), vowels.end(), [&](pair<char,int> a, pair<char,int> b) {
            if(a.second!=b.second) return a.second>b.second;
            return Map[a.first][0]<Map[b.first][0];
        });
        string ans="";
        int idx=0;
        for(auto ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                ans+=vowels[idx].first;
                vowels[idx].second-=1;
                if(vowels[idx].second==0) idx++;
            }
            else ans+=ch;
        }
        return ans;  
    }
};