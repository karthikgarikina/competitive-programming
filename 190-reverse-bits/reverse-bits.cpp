class Solution {
public:
    int reverseBits(int n) {
        bitset<32>val(n);
        for(int i=0;i<32/2;i++){
            bool temp = val[i];
            val[i] = val[31-i];
            val[31-i] = temp;

        }
        return val.to_ulong();
    }
};