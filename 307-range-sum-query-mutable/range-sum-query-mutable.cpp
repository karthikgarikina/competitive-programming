class NumArray {
public:
    struct Seg{
        int val;
        int start,end;
        Seg* left;
        Seg* right;
        Seg(int start, int end){
            this->start=start;
            this->end=end;
            val=0;
            left=NULL;
            right=NULL;
        }
    };
    Seg* buildSeg(vector<int>&nums, int st, int ed){
        Seg* root=new Seg(st,ed);
        if(st==ed){
            root->val=nums[st];
            return root;
        }
        int mid=st+(ed-st)/2;
        root->left=buildSeg(nums,st,mid);
        root->right=buildSeg(nums,mid+1,ed);
        root->val=root->right->val+root->left->val;
        return root;
    }
    int findSum(int st, int en, Seg* root){
        if(root==NULL) return 0;
        if(en<root->start or st>root->end) return 0;
        if(root->start >= st  &&  root->end <= en) return root->val;
        return (findSum(st,en,root->left)+findSum(st,en,root->right));
    }
    void updateSeg(int idx, int value, Seg* root){
        if(root->start==root->end){
            root->val=value;
            return;
        }
        int mid=(root->start+root->end)/2;
        if(idx<=mid) updateSeg(idx, value, root->left);
        else updateSeg(idx, value, root->right);
        root->val=(root->left->val+root->right->val);
    }

    Seg* root;
    NumArray(vector<int>& nums) {
        int st=0, ed=nums.size()-1;
        root=buildSeg(nums,st,ed);
    }
    
    void update(int index, int val) {
        updateSeg(index,val,root);
    }
    
    int sumRange(int left, int right) {
        return findSum(left,right,root);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */