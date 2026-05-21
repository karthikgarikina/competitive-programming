class Solution {
public:
    struct Trie{
        Trie* digit[10];
        Trie(){
            for(int i=0;i<10;i++){
                digit[i]=NULL;
            }
        }  
    };
    Trie* root=new Trie();
    void insert(int num){
        string str=to_string(num);
        Trie* start=root;
        for(auto i : str){
            int idx=i-'0';
            if(start->digit[idx]==NULL){
                Trie* newDig=new Trie();
                start->digit[idx]=newDig;
            }
            start=start->digit[idx];
        }
    }
    int prefix(int num){
        string str=to_string(num);
        Trie* start=root;
        int len=0;
        for(auto i : str){
            int idx=i-'0';
            if(start->digit[idx]==NULL) break;
            start=start->digit[idx];
            len++;
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(auto dig : arr1){
            insert(dig);
        }
        int ans=0;
        for(auto dig : arr2){
            int len=prefix(dig);
            ans=max(ans,len);
        }
        return ans;
    }
};