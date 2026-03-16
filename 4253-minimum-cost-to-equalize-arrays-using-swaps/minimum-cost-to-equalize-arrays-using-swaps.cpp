class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>Map1,Map2,extra;
        for(auto i : nums1) Map1[i]++;
        for(auto i : nums2) Map2[i]++;

        int ans=0,cnt=0,temp1=0,temp2=0;
        for(auto i : Map1){
            int val=i.first,freq1=i.second;
            if(Map2.find(val)==Map2.end()){
                if(freq1%2!=0) return -1;
                temp1+=freq1;
                continue;
            }
            int freq2=Map2[val];
            extra[val]++;
            if((freq2+freq1)%2!=0) return -1;
            int mii=min(freq1,freq2),mxx=max(freq1,freq2);
            if(freq1==mxx){
                temp1+=(mxx-mii);
            }
            else temp2+=(mxx-mii);
        }
        for(auto i : Map2){
            if(extra.find(i.first)!=extra.end()) continue;
            if(i.second%2!=0) return -1;
            temp2+=i.second;
        }
        int mini=min(temp1,temp2);
        ans+=(mini/2);
        ans+=((temp1-mini)/2);
        ans+=((temp2-mini)/2);
        return ans;
    }
};