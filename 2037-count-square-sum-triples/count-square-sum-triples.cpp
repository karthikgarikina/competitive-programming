class Solution {
public:
    int countTriples(int n) {
        unordered_map<int,bool>Map;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            Map[sq]=true;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int lhs=(i*i)+(j*j);
                if(Map.find(lhs)!=Map.end()) ans+=2;
            }
        }
        return ans;
    }
};