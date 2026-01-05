class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n=s.size(),oneS=0,oneT=0,mismatch=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]) mismatch++;
            if(s[i]=='1') oneS++;
            if(t[i]=='1') oneT++;
        }
        int diff=abs(oneS-oneT);
        long long ans=0;
        if(diff%2!=0){
            ans+=flipCost;
            mismatch--;
            diff--;
        }

        long long way1=(long)(diff/2)*(crossCost+swapCost), way2=(long)diff*flipCost;
        ans+=min(way1,way2);
        mismatch-=diff;

        way1=(long)(mismatch/2)*swapCost, way2=(long)mismatch*flipCost;
        ans+=min(way1,way2);

        return ans;
    }
};