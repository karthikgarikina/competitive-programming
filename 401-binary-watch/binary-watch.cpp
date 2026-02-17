class Solution {
public:
    vector<string>ans;
    void backtrack(vector<bool>&bits, int n, int idx){
        if(idx>9){
            int cnt=0;
            int hr=0,min=0;
            for(int i=0;i<=3;i++){
                if(bits[i]){
                    hr+=(1<<i);
                    cnt++;
                }
            }
            for(int i=4;i<10;i++){
                if(bits[i]){
                    min+=(1<<(i-4));
                    cnt++;
                }
            }
            if(cnt!=n || min>59 || hr>11) return;
            if(min<10) ans.push_back(to_string(hr)+":0"+to_string(min));
            else ans.push_back(to_string(hr)+":"+to_string(min));
            return;
        }
        bits[idx]=true;
        backtrack(bits,n,idx+1);
        bits[idx]=false;
        backtrack(bits,n,idx+1);
    }
    vector<string> readBinaryWatch(int n) {
        vector<bool>bits(10,false);
        backtrack(bits,n,0);
        return ans;
    }
};