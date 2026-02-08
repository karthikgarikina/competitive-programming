class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        stack<long long>st;
        st.push(nums[0]);
        for(int i=1;i<n;i++){
            if(st.top()!=nums[i]) st.push(nums[i]);
            else{
                long long merge=st.top()+nums[i];
                st.pop();
                while(!st.empty() and st.top()==merge){
                    merge+=st.top();
                    st.pop();
                }
                st.push(merge);
            }
        }
        int len=st.size();
        vector<long long>ans(len);
        for(int i=len-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};