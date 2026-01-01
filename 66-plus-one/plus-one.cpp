class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size(),p;
        if(digits[n-1]==9){
            p=n-2;
            while(p>=0 && digits[p]==9){
                p--; 
            }
            if( p<0){
            digits[p+1]=1;
            for(int i=p+2;i<n;i++) digits[i]=0;
            digits.push_back(0);
            }
            else{
            digits[p]+=1;
            for(int i=p+1;i<n;i++) digits[i]=0;
            }
        }
        else digits[digits.size()-1]=digits[digits.size()-1]+1;
        return digits;
        
    }
};