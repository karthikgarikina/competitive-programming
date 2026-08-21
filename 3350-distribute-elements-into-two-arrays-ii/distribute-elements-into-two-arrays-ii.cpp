#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
        int,
        null_type,
        less_equal<int>,
        rb_tree_tag,
        tree_order_statistics_node_update
        > multiset_pbds;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr1, brr1;
        multiset_pbds arr2, brr2;

        arr1.push_back(nums[0]);
        arr2.insert(nums[0]);

        brr1.push_back(nums[1]);
        brr2.insert(nums[1]);

        for(int i = 2; i < n; i++){
            int arr_mins = arr2.order_of_key(nums[i] + 1);
            int brr_mins = brr2.order_of_key(nums[i] + 1);
            int a = arr1.size(), b = brr1.size();
            int arr_maxs = (a - arr_mins), brr_maxs = (b - brr_mins);

            if(arr_maxs > brr_maxs){
                arr1.push_back(nums[i]);
                arr2.insert(nums[i]);
            }
            else if(brr_maxs > arr_maxs){
                brr1.push_back(nums[i]);
                brr2.insert(nums[i]);
            }
            else{
                if(b < a){
                    brr1.push_back(nums[i]);
                    brr2.insert(nums[i]);
                }
                else{
                    arr1.push_back(nums[i]);
                    arr2.insert(nums[i]);
                }
            }
        }

        arr1.insert(arr1.end(), brr1.begin(), brr1.end());
        return arr1;
    }
};