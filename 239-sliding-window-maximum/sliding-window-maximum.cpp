class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int>dq;
        vector<int>ans;
        int st=0,n=arr.size();

        for(int i=0;i<n;i++){
            while(!dq.empty() and dq.back()<arr[i]){
                dq.pop_back();
            }
            dq.push_back(arr[i]);
            
            if((i-st+1)==k){
                ans.push_back(dq.front());
                if(dq.front()==arr[st]){
                    dq.pop_front();
                }
                st++;
            }
        }
        return ans;
        
    }
};