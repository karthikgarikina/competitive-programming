class Solution {
public:
    void mergeSort(int i, int mid, int j, vector<int>& nums){
        int len = (j - i + 1);
        vector<int>temp(len);
        int st1 = i, st2 = mid + 1, idx = 0;
        while(st1 <= mid and st2 <= j){
            if(nums[st1] < nums[st2]){
                temp[idx++] = nums[st1++];
            }
            else temp[idx++] = nums[st2++];
        }
        while(st1 <= mid) temp[idx++] = nums[st1++];
        while(st2 <= j) temp[idx++] = nums[st2++];
        idx = 0;
        for(int k = i; k <= j; k++, idx++) nums[k] = temp[idx];
    }
    void merge(int i, int j, vector<int>& nums){
        if(i == j) return;
        int mid = i + (j - i) / 2;
        merge(i, mid, nums);
        merge(mid + 1, j, nums);
        mergeSort(i , mid, j, nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        merge(i, j, nums);
        return nums;
    }
};