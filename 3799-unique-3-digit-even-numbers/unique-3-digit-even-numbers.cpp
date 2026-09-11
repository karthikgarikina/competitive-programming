class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for(auto i : digits) freq[i]++;
        int valid_nums = 0;
        for(int i = 100; i <= 998; i += 2){
            int d1 = i / 100;
            int d2 = (i / 10) % 10;
            int d3 = i % 10;

            freq[d1]--, freq[d2]--, freq[d3]--;
            if(freq[d1] >= 0 and freq[d2] >= 0 and freq[d3] >= 0) valid_nums++;
            freq[d1]++, freq[d2]++, freq[d3]++;
        }
        return valid_nums;
    }
};