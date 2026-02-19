class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size(),arr[2]={0,0},ans=0;
        arr[s[0]-'0']++;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                arr[s[i]-'0']++;
            }
            else{
                ans+=min(arr[0],arr[1]);
                arr[s[i]-'0']=1;
            }
        }
        ans+=min(arr[0],arr[1]);
        return ans;
    }
};