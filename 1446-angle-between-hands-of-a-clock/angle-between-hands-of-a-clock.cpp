class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mi=(minutes*1.0),hr=(hour%12*5.0+mi/12.0);
        double dif1=abs(mi-hr),dif2=abs(60+min(hr,mi)-max(hr,mi));
        return min((dif1*6.0),(dif2*6.0));
    }
};