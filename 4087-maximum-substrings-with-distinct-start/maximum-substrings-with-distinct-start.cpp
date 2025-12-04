class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char,bool>Map;
        for(auto ch : s) Map[ch]=true;
        return Map.size();
    }
};