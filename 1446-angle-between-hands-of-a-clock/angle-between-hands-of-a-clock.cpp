class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12) hour=0;
        double hr=(hour*5*1.0),mi=(minutes*1.0);
        hr+=(mi/12.0);
        double dif1=abs(mi-hr),dif2=abs(60+min(hr,mi)-max(hr,mi));
        double minAngle=min((dif1*6.0),(dif2*6.0));
        return minAngle;
    }
};