class Solution {
public:
    struct TrieNode{
        int val,cnt;
        TrieNode* arr[2];
        TrieNode(){
            val=0,cnt=0;
            arr[0]=NULL,arr[1]=NULL;
        }
    };
    int SIZE=32;
    void insert(TrieNode* Trie, int pre){
        TrieNode* temp=Trie;
        for(int i=SIZE-1;i>=0;i--){
            int bit=((pre>>i)&1);
            if(temp->arr[bit]==NULL){
                temp->arr[bit]=new TrieNode();
            }
            temp=temp->arr[bit];
            temp->cnt++;
        }
        temp->val=pre;
    }
    void deletePre(TrieNode* Trie, int pre){
        TrieNode* temp=Trie;
        for(int i=SIZE-1;i>=0;i--){
            int bit=((pre>>i)&1);
            TrieNode* next=temp->arr[bit];
            if(!next) return;
            next->cnt--;
            if(next->cnt==0){
                delete next;
                temp->arr[bit]=NULL;
                return;
            }
            temp=next;
        }
    }
    int findMax(TrieNode* Trie, int pre){
        TrieNode* temp=Trie;
        for(int i=SIZE-1;i>=0;i--){
            int bit=((pre>>i)&1);
            if(temp->arr[!bit]!=NULL && temp->arr[!bit]->cnt>0){
                temp=temp->arr[!bit];
            }
            else if(temp->arr[bit]!=NULL && temp->arr[bit]->cnt>0){
                temp=temp->arr[bit];
            }
        }
        return (temp->val^pre);
    }
    int maxXor(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pref(n+1,0);
        for(int i=0;i<n;i++) pref[i+1]=pref[i]^nums[i];

        deque<int>mini,maxi;
        TrieNode* Trie = new TrieNode();
        insert(Trie,0);
        int st=0,ans=INT_MIN;
        for(int i=0;i<n;i++){
            while(!mini.empty() and nums[i]<nums[mini.back()]) mini.pop_back();
            while(!maxi.empty() and nums[i]>nums[maxi.back()]) maxi.pop_back();
            mini.push_back(i);
            maxi.push_back(i);

            while(nums[maxi.front()]-nums[mini.front()]>k){
                deletePre(Trie,pref[st]);
                st++;
                if(mini.front()<st) mini.pop_front();
                if(maxi.front()<st) maxi.pop_front();
            }

            int pre=pref[i+1];
            int maxiX=findMax(Trie,pre);
            ans=max(ans,maxiX);
            insert(Trie,pre);
        }
        return ans;
    }
};
