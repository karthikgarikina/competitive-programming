class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int n=capacity.size(), total=accumulate(apple.begin(),apple.end(),0);
        for(int i=0;i<n;i++){
            total-=capacity[i];
            if(total<=0) return i+1;
        }
        return n;
    }
};