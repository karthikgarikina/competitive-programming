class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<long long>times;
        times.push_back(skill[0]*mana[0]);
        for(int i=1;i<n;i++){
            times.push_back((skill[i]*mana[0])+times[i-1]);
        }
        for(int i=1;i<m;i++){
            long long addTime=skill[n-1]*mana[i];
            long long cur=times[n-1];
            times[n-1]+=addTime;
            vector<long long>prefix(n,0);
            for(int j=n-2;j>=0;j--){
                long long addTime=skill[j]*mana[i];
                long long wizard=cur-addTime;
                if(times[j]<=wizard){
                    times[j]=cur;
                    cur=wizard;
                }
                else{
                    long long add=abs(times[j]-wizard);
                    // for(int t=j+1;t<n;t++) times[t]+=add;
                    prefix[j+1]+=add;
                    times[j]=add+cur;
                    cur=times[j]-addTime;
                }

            }
            long long sum=0;
            for(int t=0;t<n;t++){
                sum+=prefix[t];
                times[t]+=sum;
            }
        }
        return times[n-1];
        
    }
};