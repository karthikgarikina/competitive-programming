class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>speed(100,vector<double>(100,0.0));
        speed[0][0]=(poured+0.0);
        for(int i=0;i<100-1;i++){
            for(int j=0;j<=i;j++){
                if(speed[i][j]-1>0){
                    speed[i+1][j]+=((speed[i][j]-1.0)*0.5);
                    speed[i+1][j+1]+=((speed[i][j]-1.0)*0.5);   
                }
            }
        }
        return min(1.0,speed[query_row][query_glass]);
    }
};