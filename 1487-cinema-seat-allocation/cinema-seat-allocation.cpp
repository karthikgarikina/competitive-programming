class Solution {
public:
    int actual(int row){
        int cnt = 0;
        if( !(row & (1 << 2)) and !(row & (1 << 3)) and !(row & (1 << 4)) and !(row & (1 << 5)) ) cnt++;
        if( !(row & (1 << 6)) and !(row & (1 << 7)) and !(row & (1 << 8)) and !(row & (1 << 9)) ) cnt++;

        if( !(row & (1 << 4)) and !(row & (1 << 5)) and !(row & (1 << 6)) and !(row & (1 << 7)) and cnt == 0 ) cnt++;

        return (2 - cnt);
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int>effected_rows;
        for(auto &p : reservedSeats){
            int row = p[0], posi = p[1];
            if( !effected_rows.count(row) ) effected_rows[row] = 0;
            effected_rows[row] = ( effected_rows[row] | (1 << posi) );
        }
        int ans = n * 2;
        for(auto &i : effected_rows){
            int row = i.second;
            ans -= actual(row);
        }
        return ans;
    }
};