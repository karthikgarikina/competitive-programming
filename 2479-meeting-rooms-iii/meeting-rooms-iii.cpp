class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<pair<long long,int>>arr(n,{0,0});
        for(auto i : meetings){
            long long st=i[0],ed=i[1],len=ed-st,curl=LLONG_MAX;
            int idx1=-1,idx2=-1;
            for(int j=0;j<n;j++){
                if(arr[j].first<=st){
                    idx1=j;
                    break;
                }
                else if(arr[j].first<curl){
                    idx2=j;
                    curl=arr[j].first;
                }
            }
            if(idx1!=-1){
                arr[idx1].second++;
                arr[idx1].first=ed;
            }
            else{
                arr[idx2].second++;
                arr[idx2].first+=len;
            }
        }
        int ans=0;
        long long maxi=-1;
        for(int i=0;i<n;i++){
            if(maxi<arr[i].second){
                ans=i;
                maxi=arr[i].second;
            }
        }
        return ans;
    }
};