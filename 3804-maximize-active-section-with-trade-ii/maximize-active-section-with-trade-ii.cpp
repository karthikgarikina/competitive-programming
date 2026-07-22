class Solution {
public:
    void buildTree(vector<pair<int, array<int, 5>>>& segTree, int idx, int i, int j, const string& s){
        if(i == j){
            segTree[idx].first = 0;
            if(s[i] == '0') segTree[idx].second = {1, 1, 0, 0, 1};
            else segTree[idx].second = {0, 0, 0, 0, 0};
            return;
        }
        int mid = (i + j) / 2;
        buildTree(segTree, idx * 2 + 1, i, mid, s);
        buildTree(segTree, idx * 2 + 2, mid + 1, j, s);
        
        int sz1 = segTree[idx * 2 + 1].second[0], l1_1 = segTree[idx * 2 + 1].second[1], l2_1 = segTree[idx * 2 + 1].second[2], r2_1 = segTree[idx * 2 + 1].second[3], r1_1 = segTree[idx * 2 + 1].second[4];
        int sz2 = segTree[idx * 2 + 2].second[0], l1_2 = segTree[idx * 2 + 2].second[1], l2_2 = segTree[idx * 2 + 2].second[2], r2_2 = segTree[idx * 2 + 2].second[3], r1_2 = segTree[idx * 2 + 2].second[4];
        
        int maxi = max(segTree[idx * 2 + 1].first, segTree[idx * 2 + 2].first);
        int sz = 0, l1 = 0, l2 = 0, r2 = 0, r1 = 0;
        
        if(s[mid] == '0' and s[mid + 1] == '0' and sz1 > 0 and sz2 > 0){
            int merged = r1_1 + l1_2;
            if(sz1 >= 2) maxi = max(maxi, r2_1 + merged);
            if(sz2 >= 2) maxi = max(maxi, merged + l2_2);
            
            sz = sz1 + sz2 - 1;
            
            if (sz1 >= 3) { l1 = l1_1; l2 = l2_1; }
            else if (sz1 == 2) { l1 = l1_1; l2 = merged; }
            else { l1 = merged; l2 = (sz2 >= 2) ? l2_2 : 0; }
            
            if (sz2 >= 3) { r1 = r1_2; r2 = r2_2; }
            else if (sz2 == 2) { r1 = r1_2; r2 = merged; }
            else { r1 = merged; r2 = (sz1 >= 2) ? r2_1 : 0; }
        }
        else{
            if(sz1 > 0 && sz2 > 0) maxi = max(maxi, r1_1 + l1_2);
            
            sz = sz1 + sz2;
            if(sz1 == 0) {
                l1 = l1_2; l2 = l2_2; r1 = r1_2; r2 = r2_2;
            } else if(sz2 == 0) {
                l1 = l1_1; l2 = l2_1; r1 = r1_1; r2 = r2_1;
            } else {
                l1 = l1_1; l2 = (sz1 >= 2) ? l2_1 : l1_2;
                r1 = r1_2; r2 = (sz2 >= 2) ? r2_2 : r1_1;
            }
        }
        
        if (sz == 1) { r1 = l1; l2 = 0; r2 = 0; }
        else if (sz == 2) { r2 = l1; l2 = r1; }
        
        segTree[idx].first = maxi;
        segTree[idx].second = {sz, l1, l2, r2, r1};
    }

    pair<int, array<int, 5>> query(vector<pair<int, array<int, 5>>>& segTree, int idx, int i, int j, int l, int r, const string& s){
        if(j < l || i > r) return {0, {0, 0, 0, 0, 0}};
        if(i >= l and j <= r) return segTree[idx];
        
        int mid = (i + j) / 2;
        auto left = query(segTree, 2 * idx + 1, i, mid, l, r, s);
        auto right = query(segTree, 2 * idx + 2, mid + 1, j, l, r, s);
        
        int sz1 = left.second[0], l1_1 = left.second[1], l2_1 = left.second[2], r2_1 = left.second[3], r1_1 = left.second[4];
        int sz2 = right.second[0], l1_2 = right.second[1], l2_2 = right.second[2], r2_2 = right.second[3], r1_2 = right.second[4];
        
        int maxi = max(left.first, right.first);
        int sz = 0, l1 = 0, l2 = 0, r2 = 0, r1 = 0;
        
        if(s[mid] == '0' and s[mid + 1] == '0' and sz1 > 0 and sz2 > 0){
            int merged = r1_1 + l1_2;
            if(sz1 >= 2) maxi = max(maxi, r2_1 + merged);
            if(sz2 >= 2) maxi = max(maxi, merged + l2_2);
            
            sz = sz1 + sz2 - 1;
            
            if (sz1 >= 3) { l1 = l1_1; l2 = l2_1; }
            else if (sz1 == 2) { l1 = l1_1; l2 = merged; }
            else { l1 = merged; l2 = (sz2 >= 2) ? l2_2 : 0; }
            
            if (sz2 >= 3) { r1 = r1_2; r2 = r2_2; }
            else if (sz2 == 2) { r1 = r1_2; r2 = merged; }
            else { r1 = merged; r2 = (sz1 >= 2) ? r2_1 : 0; }
        }
        else{
            if(sz1 > 0 && sz2 > 0) maxi = max(maxi, r1_1 + l1_2);
            
            sz = sz1 + sz2;
            if(sz1 == 0) {
                l1 = l1_2; l2 = l2_2; r1 = r1_2; r2 = r2_2;
            } else if(sz2 == 0) {
                l1 = l1_1; l2 = l2_1; r1 = r1_1; r2 = r2_1;
            } else {
                l1 = l1_1; l2 = (sz1 >= 2) ? l2_1 : l1_2;
                r1 = r1_2; r2 = (sz2 >= 2) ? r2_2 : r1_1;
            }
        }
        
        if (sz == 1) { r1 = l1; l2 = 0; r2 = 0; }
        else if (sz == 2) { r2 = l1; l2 = r1; }
        
        return {maxi, {sz, l1, l2, r2, r1}};
    }

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = 0;
        for(auto ch : s){
            if(ch == '1') ones++;
        }
        vector<pair<int, array<int, 5>>> segTree(4 * n);
        buildTree(segTree, 0, 0, n - 1, s);
        vector<int> ans;
        for(const auto& i : queries){
            int l = i[0], r = i[1];
            auto maxZeros = query(segTree, 0, 0, n - 1, l, r, s);
            ans.push_back(ones + maxZeros.first);
        }
        return ans;
    }
};