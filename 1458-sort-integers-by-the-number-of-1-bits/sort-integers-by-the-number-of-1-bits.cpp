class Solution {
public:
    static bool comp(int a1, int b1){
        int a=a1,b=b1;
        int ac=0,bc=0;
        while(a>0){
            if(a&1) ac++;
            a=a>>1;
        }
        while(b>0){
            if(b&1) bc++;
            b=b>>1;
        }
        if(ac==bc) return a1<b1;
        return ac<bc;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};