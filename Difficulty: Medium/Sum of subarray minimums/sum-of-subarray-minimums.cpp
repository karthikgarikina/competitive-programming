class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int windSum=0,totalSum=0;
        stack<pair<int,int>>st;
        for(auto i : arr){
            int freq=1;
            while(!st.empty() and st.top().first>i){
                freq+=st.top().second;
                windSum-=(st.top().first*st.top().second);
                st.pop();
            }
            windSum+=(i*freq);
            st.push({i,freq});
            totalSum+=windSum;
        }
        return totalSum;
    }
};