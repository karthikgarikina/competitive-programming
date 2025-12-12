class Solution {
public:
    static bool comp(const vector<string>&a, const vector<string>&b){
        return stoi(a[1])<stoi(b[1]);
    }
    bool check(vector<pair<int,int>>&user, int time){
        for(auto i : user){
            int a=i.first,b=i.second;
            if(time>=a and time<b) return false;
        }
        return true;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n=numberOfUsers;
        vector<vector<string>>offline,message;
        for(auto i : events){
            if(i[0]=="MESSAGE"){
                message.push_back(i);
            }
            else offline.push_back(i);
        }
        sort(offline.begin(),offline.end(),comp);
        vector<vector<pair<int,int>>>inOff(n);
        for(auto i : offline){
            int st=stoi(i[1]);
            int ed=st+60,idx=stoi(i[2]);
            if(inOff[idx].size()==0) inOff[idx].push_back({st,ed});
            else{
                auto ab=inOff[idx].back();
                if(st<=ab.second){
                    inOff[idx].pop_back();
                    inOff[idx].push_back({ab.first,ed});
                }
                else{
                    inOff[idx].push_back({st,ed});
                }
            }
        }
        vector<int>ans(n,0);
        for(auto i : message){
            int time=stoi(i[1]);
            string mode=i[2];
            if(mode=="ALL"){
                for(int i=0;i<n;i++) ans[i]++;
            }
            else if(mode=="HERE"){
                for(int i=0;i<n;i++){
                    if(check(inOff[i],time)) ans[i]++;
                }
            }
            else{
                stringstream ss(mode);
                string str;
                while(ss>>str){
                    int idx=stoi(str.substr(2));
                    ans[idx]++;
                }
            }
        }
        return ans;
    }
};