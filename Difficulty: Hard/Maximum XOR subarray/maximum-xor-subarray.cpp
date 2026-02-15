// User function Template for C++

class Solution {
  public:
    int SIZE=32;
    struct TrieNode{
        int val;
        TrieNode* arr[2];
        TrieNode(){
            val=0;
            arr[0]=NULL;
            arr[1]=NULL;
        }
    };
    void insert(TrieNode* root,int pre){
        TrieNode* temp=root;
        for(int i=SIZE-1;i>=0;i--){
            int bit=((pre>>i)&1);
            if(temp->arr[bit]==NULL){
                temp->arr[bit]=new TrieNode();
            }
            temp=temp->arr[bit];
        }
        temp->val=pre;
    }
    int findMax(TrieNode* root, int pre){
        TrieNode* temp=root;
        for(int i=SIZE-1;i>=0;i--){
            int bit=((pre>>i)&1);
            if(temp->arr[!bit]!=NULL){
                temp=temp->arr[!bit];
            }
            else if(temp->arr[bit]!=NULL){
                temp=temp->arr[bit];
            }
        }
        return ((temp->val)^pre);
    }
    int maxSubarrayXOR(int N, int arr[]) {
        int pre_xor=0, ans=INT_MIN;
        TrieNode* root=new TrieNode();
        insert(root,pre_xor);
        for(int i=0;i<N;i++){
            pre_xor^=arr[i];
            insert(root,pre_xor);
            int maxi=findMax(root,pre_xor);
            ans=max(ans,maxi);
        }
        return ans;
    }
};