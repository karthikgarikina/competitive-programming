class Solution {
public:
    string ans="";
    int cnt=0;
    
    bool find(int idx, int n, string curn, int k){
        if(idx==n){
            cnt++;
            if(cnt==k){
                ans=curn;
                return true;
            }
            else{
                return false;
            }
        }

        for(int i=0;i<3;i++){
            if(idx!=0 and curn.back()==char('a'+i) ) continue;
            curn+=char('a'+i);
            if(find(idx+1,n,curn,k)) return true;
            curn.pop_back();
        }
        return false;
    }
    string getHappyString(int n, int k) {
        string curn="";
        find(0,n,curn,k);
        return ans;
    }
};