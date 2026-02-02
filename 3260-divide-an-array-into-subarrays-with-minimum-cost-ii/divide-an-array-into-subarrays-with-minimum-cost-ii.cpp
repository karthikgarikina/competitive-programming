class Solution {
public:
    template<typename Heap>
    pair<long long, int> findtop(Heap &pq, vector<bool>died){
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            if(!died[top.second]) return top;
        }
        return {-1,-1};
    }
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long ans=nums[0], rem=0;
        k=k-1;
        int n=nums.size();
        vector<bool>died(n,false),contain(n,false);
        priority_queue<pair<long long,int>>inUse;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> >canUse;
        for(int i=1;i<=dist+1;i++){
            rem+=nums[i];
            contain[i]=true;
            inUse.push({nums[i],i});
        }
        int noneed=dist-k+1;
        while(noneed--){
            auto [num,idx]=inUse.top();
            inUse.pop();
            contain[idx]=false;
            rem-=num;
            canUse.push({num,idx});
        }

        long long minRem=rem;
        int st=1;
        for(int i=dist+2;i<n;i++){
            canUse.push({nums[i],i});
            died[st]=true;
            if(contain[st]){
                auto canAdd=findtop(canUse,died);
                rem-=nums[st];
                rem+=canAdd.first;
                inUse.push(canAdd);
                contain[canAdd.second]=true;
                contain[st]=false;
            }
            else{
                auto canAdd=findtop(canUse,died);
                auto added=findtop(inUse,died);
                if(canAdd.first<added.first){
                    contain[added.second]=false;
                    contain[canAdd.second]=true;
                    rem-=added.first;
                    rem+=canAdd.first;
                    canUse.push(added);
                    inUse.push(canAdd);
                }
                else{
                    canUse.push(canAdd);
                    inUse.push(added);
                }
            }

            minRem=min(minRem,rem);
            st++;
        }
        return (minRem+ans);
    }
};