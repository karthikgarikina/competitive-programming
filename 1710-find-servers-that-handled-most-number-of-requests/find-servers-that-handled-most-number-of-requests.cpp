class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();
        set<long long>available;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>busy;
        unordered_map<long long, long long>cnt;
        int maxi=INT_MIN;
        vector<int>ans;
        for(int i=0;i<k;i++) available.insert(i);
        for(int i=0;i<n;i++){
            long long ari=arrival[i],loa=load[i];
            long long burst=ari+loa;
            while(!busy.empty() and busy.top().first<=ari){
                auto pair=busy.top();
                busy.pop();
                available.insert(pair.second);
            }
            long long server=i%k;
            auto it=available.lower_bound(server);
            if(it!=available.end()){
                long long got=*it;
                cnt[got]++;
                busy.push({burst,got});
                available.erase(got);

                if(cnt[got]>maxi){
                    maxi=cnt[got];
                    ans.clear();
                    ans.push_back(got);
                }
                else if(cnt[got]==maxi) ans.push_back(got);
            }
            else if(available.size()!=0 and it==available.end()){
                it=available.begin();
                long long got=*it;
                cnt[got]++;
                busy.push({burst,got});
                available.erase(got);

                if(cnt[got]>maxi){
                    maxi=cnt[got];
                    ans.clear();
                    ans.push_back(got);
                }
                else if(cnt[got]==maxi) ans.push_back(got);
            }
        }
        return ans;


    }
};