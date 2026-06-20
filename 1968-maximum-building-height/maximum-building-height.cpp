class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rest) {
        rest.push_back({1,0});
        int len = rest.size();
        sort(rest.begin(), rest.end());
        vector<int>maxis;
        for(int i = 1; i < len; i++){
            int prev = rest[i-1][0], prevLim = rest[i-1][1], curnt = rest[i][0], curntLim = rest[i][1];
            if(prevLim <= curntLim){
                int dif = curnt-prev;
                int canMax = prevLim+dif;
                if(canMax > curntLim){
                    canMax -= abs(canMax-curntLim+1)/2;
                }
                else{
                    rest[i][1] = canMax;
                }
                maxis.push_back(canMax);
            }
            else{
                int dif = curnt-prev;
                int canMax = prevLim+dif;
                if(prevLim-dif <= curntLim){
                    canMax -= abs(canMax-curntLim+1)/2;
                    maxis.push_back(canMax);
                }
                else{
                    int ed=i-2;
                    if(rest[ed][0] == -1) ed = rest[ed][1];
                    while(ed>=0){
                        int last = rest[ed][0], lastLim = rest[ed][1];
                        maxis.pop_back();
                        if(lastLim <= curntLim){
                            int dif = curnt-last;
                            int canMax = lastLim+dif;
                            if(canMax > curntLim){
                                canMax -= abs(canMax-curntLim+1)/2;
                            }
                            else{
                                rest[i][1] = canMax;
                            }
                            maxis.push_back(canMax);
                            rest[i-1][0] = -1, rest[i-1][1] = ed;
                            break;
                        }
                        else{
                            int dif = curnt-last;
                            int canMax = lastLim+dif;
                            if(lastLim-dif <= curntLim){
                                canMax -= abs(canMax-curntLim+1)/2;
                                maxis.push_back(canMax);
                                rest[i-1][0] = -1, rest[i-1][1] = ed;
                                break;
                            }
                            else{
                                ed--;
                                if(rest[ed][0]==-1) ed=rest[ed][1];
                            }
                        }

                    }
                }

            }
        }
        maxis.push_back(rest.back()[1]+(n-rest.back()[0]));
        int ans=0;
        for(auto i : maxis){
            ans = max(i,ans);
        }
        return ans;
    }
};