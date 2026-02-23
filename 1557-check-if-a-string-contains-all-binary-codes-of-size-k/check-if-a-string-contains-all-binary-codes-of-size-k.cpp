class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,bool>Map;;
        int n=s.size();
        for(int i=0;i<=n-k;i++){
            string sub=s.substr(i,k);
            Map[sub]=true;
        }
        for(int i=0;i<(1<<k);i++){
            string str = bitset<32>(i).to_string();
            str=str.substr(32-k);
            if(Map.find(str)==Map.end()) return false;
        }
        return true;
    }
};