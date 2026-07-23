class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>>Map;
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            sort(str.begin(),str.end());
            Map[str].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto st : Map){
            vector<string>str;
            for(auto i : st.second){
                str.push_back(strs[i]);
            }
            ans.push_back(str);
        }
        return ans;
        
    }
};