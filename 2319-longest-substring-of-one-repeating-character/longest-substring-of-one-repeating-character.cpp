struct Node {
    int left;
    int right;
    int maxi;
};

class Solution {
public:
    void buildTree(int idx, int l, int r, string& s, vector<Node>& segTree){
        if(l == r){
            segTree[idx] = {1, 1, 1};
            return;
        }
        int mid = (r + l) / 2;
        int leftIdx = idx * 2 + 1;
        int rightIdx = idx * 2 + 2;
        buildTree(leftIdx, l, mid, s, segTree);
        buildTree(rightIdx, mid + 1, r, s, segTree);
        
        int maxi = 1, left = segTree[leftIdx].left, right = segTree[rightIdx].right;
        if(s[mid] == s[mid + 1]){
            maxi = segTree[leftIdx].right + segTree[rightIdx].left;
            if((mid - l + 1) == segTree[leftIdx].left) left = maxi;
            if((r - mid) == segTree[rightIdx].right) right = maxi;
        }
        maxi = max({maxi, segTree[leftIdx].maxi, segTree[rightIdx].maxi});
        segTree[idx] = {left, right, maxi};
    }

    void query(int idx, int l, int r, int t, string& s, vector<Node>& segTree){
        if(l == t and r == t){
            segTree[idx] = {1, 1, 1};
            return;
        }
        int mid = (r + l) / 2;
        int leftIdx = idx * 2 + 1;
        int rightIdx = idx * 2 + 2;
        if(t >= l and t <= mid){
            query(leftIdx, l, mid, t, s, segTree);
        }
        if(t >= mid + 1 and t <= r){
            query(rightIdx, mid + 1, r, t, s, segTree);
        }
        
        int maxi = 1, left = segTree[leftIdx].left, right = segTree[rightIdx].right;
        if(s[mid] == s[mid + 1]){
            maxi = segTree[leftIdx].right + segTree[rightIdx].left;
            if((mid - l + 1) == segTree[leftIdx].left) left = maxi;
            if((r - mid) == segTree[rightIdx].right) right = maxi;
        }
        maxi = max({maxi, segTree[leftIdx].maxi, segTree[rightIdx].maxi});
        segTree[idx] = {left, right, maxi};
    }

    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        int n = s.size();
        vector<Node> segTree(n * 4);
        buildTree(0, 0, n - 1, s, segTree);
        
        int q = qi.size();
        vector<int> ans(q);
        for(int i = 0; i < q; i++){
            int idx = qi[i];
            char ch = qc[i];
            s[idx] = ch;
            query(0, 0, n - 1, idx, s, segTree);
            ans[i] = segTree[0].maxi;
        }
        return ans;
    }
};