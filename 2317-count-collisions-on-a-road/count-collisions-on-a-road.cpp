class Solution {
public:
    int countCollisions(string directions) {
        int left=-1,idx=0,n=directions.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(directions[i]=='L'){
                if(left==-1) continue;
                else{
                    ans+=(left+1);
                    left=0;
                }
            }
            else if(directions[i]=='S'){
                if(left==-1) left=0;
                else{
                    ans+=(left);
                    left=0;
                }
            }
            else if(directions[i]=='R'){
                if(left==-1) left=1;
                else{
                    left++;
                }
            }
        }
        return ans;
    }
};