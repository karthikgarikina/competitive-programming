class Solution {
public:
    int numberOfWays(string corridor) {
        long long ans=1,plants=0,seats=0;
        long long mod=1e9+7;
        for(auto ch : corridor){
            if(ch=='S'){
                if(seats==2){
                    ans=(ans*(plants+1))%mod;
                    plants=0;
                    seats=0;
                }
                seats++;
            }
            else{
                if(seats==2){
                    plants++;
                }
            }
        }
        if(seats!=2) return 0;
        return ans;

    }
};