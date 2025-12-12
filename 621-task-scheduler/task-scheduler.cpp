class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char ch : tasks ){
            int idx=(ch-'A');
            freq[idx]++;
        }
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push({freq[i],i});
        }
        int ans=0,cur=0;
        bool flag=true;
        while(!pq.empty()){
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    auto pair=pq.top();
                    pq.pop();
                    cur++;
                    freq[pair.second]=pair.first-1;
                    if(pair.first-1>0) flag=false;
                }
                else{
                    break;
                }
            }
            if(flag){
                ans+=cur;
            }
            else ans+=(n+1);
            cur=0;
            flag=true;
            while(!pq.empty()) pq.pop();
            for(int i=0;i<26;i++){
                if(freq[i]>0) pq.push({freq[i],i});
            }
        }
        return ans;
        
    }
};