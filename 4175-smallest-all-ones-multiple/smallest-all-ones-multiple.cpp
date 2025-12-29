class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 or k%5==0) return -1;
        int rem=1,ans=1;
        while(true){
            if(rem==0) return ans;
            rem=(rem*10+1);
            rem=rem%k;
            ans++;
        }
    }
};