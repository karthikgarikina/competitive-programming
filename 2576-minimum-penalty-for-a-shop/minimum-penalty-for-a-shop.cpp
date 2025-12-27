class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size(),ycount=0,ncount=0;
        int minPen=ycount,ans=0;
        for(int i=0;i<n;i++){
            char ch=customers[i];
            if(ch=='Y') ycount--;
            else ncount++;
            int pen=ncount+ycount;
            if(pen<minPen){
                minPen=pen;
                ans=i+1;
            }
        }
        return ans;
    }
};