class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<set<int>>rows(n+1),cols(n+1);
        for(auto i : buildings){
            int x=i[0],y=i[1];
            rows[x].insert(y);
            cols[y].insert(x);
        }
        int ans=0;
        for(auto i : buildings){
            int x=i[0],y=i[1];
            bool left=*rows[x].begin()!=y;
            if(!left) continue;
            bool right = rows[x].upper_bound(y) != rows[x].end();
            if(!right) continue;
            bool top = cols[y].upper_bound(x) != cols[y].end();
            if(!top) continue;
            bool bottom=*cols[y].begin()!=x;
            if(!bottom) continue;
            ans++;
        }
        return ans;
    }
};