class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int hCnt=1,vCnt=1, hMax=1,vMax=1;

        for(int i=0;i<hBars.size()-1;i++){
            if(hBars[i]==1 or hBars[i+1]==2+n) continue;
            if(hBars[i]+1==hBars[i+1]){
                hCnt++;
            }
            else{
                hMax=max(hMax,hCnt);
                hCnt=1;
            }
        }
        hMax=max(hMax,hCnt);
        
        for(int i=0;i<vBars.size()-1;i++){
            if(vBars[i]==1 or vBars[i+1]==2+m) continue;
            if(vBars[i]+1==vBars[i+1]){
                vCnt++;
            }
            else{
                vMax=max(vMax,vCnt);
                vCnt=1;
            }
        }
        vMax=max(vMax,vCnt);

        int side=min(hMax,vMax)+1;
        return side*side;
    }
};