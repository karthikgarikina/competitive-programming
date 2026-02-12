class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        unordered_map<int,int>freq;
        for(auto i : people) freq[i[0]]++;
        sort(people.begin(),people.end(),greater<vector<int>>());
        vector<vector<int>>ans;
        for(auto i : people){
            freq[i[0]]--;
            int posi=abs(freq[i[0]]-i[1]);
            ans.insert(ans.begin()+posi,i);
        }
        return ans;
    }
};