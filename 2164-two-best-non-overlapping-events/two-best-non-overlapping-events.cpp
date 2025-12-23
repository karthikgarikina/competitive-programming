class Solution {
public:
    static bool comp(const vector<int>&a, const vector<int>&b){
        return a[1]<b[1];
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        auto it=*events.rbegin();
        sort(events.begin(),events.end(),comp);
        vector<int>dp,maxi;
        int ans=0;
        for(auto i : events){
            int st=i[0],ed=i[1],val=i[2];
            if(!dp.empty()){
                auto it=lower_bound(dp.begin(),dp.end(),st);
                int score=val;
                if(it!=dp.begin()){
                    it--;
                    int idx=it-dp.begin();
                    score+=maxi[idx];
                }
                ans=max(ans,score);
            }
            else ans=val;

            if(dp.empty()){
                dp.push_back(ed);
                maxi.push_back(val);
            }
            if(*(dp.end()-1)==ed){
                maxi.back()=max(maxi.back(),val);
            }
            else{
                maxi.push_back(max(maxi.back(),val));
                dp.push_back(ed);
            }

        }
        return ans;
    }
};