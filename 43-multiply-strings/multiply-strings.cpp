class Solution {
public:
    string multiply(string num1, string num2) {
        vector<vector<int>>multi;
        int n=num1.size(),m=num2.size(),rem=0,empty=-1;
        for(int i=n-1;i>=0;i--){
            empty++;
            vector<int>arr;
            for(int e=0;e<empty;e++) arr.push_back(0);
            for(int j=m-1;j>=0;j--){
                int temp=(num1[i]-'0')*(num2[j]-'0');
                temp+=rem;
                rem=0;
                if(j!=0){
                    rem=temp/10;
                    int dig=temp%10;
                    arr.push_back(dig);
                }
                else arr.push_back(temp);
            }
            multi.push_back(arr);
        }

        int n1=multi.size(),n2=multi[n1-1].size();
        rem=0;
        string ans="",final="";
        for(int j=0;j<n2;j++){
            long long digit=0;
            for(int i=0;i<n1;i++){
                if(multi[i].size()-1>=j) digit+=multi[i][j];
            }
            digit+=rem;
            if(j==n2-1){
                final=to_string(digit);
            }
            else{
                ans+=to_string(digit%10);
                rem=digit/10;
            }
        }
        reverse(ans.begin(),ans.end());
        ans=final+ans;
        while(ans.size()>0 and ans[0]=='0') ans.erase(ans.begin());
        return (ans=="")?"0":ans;
    }
};