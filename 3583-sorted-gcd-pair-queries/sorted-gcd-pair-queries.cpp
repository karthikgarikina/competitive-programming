class Solution {
public:
    void findFactors(int num, vector<vector<int>>& possibilites){
        for(int i = 1; i * i <= num; i++){
            if(num % i == 0){
                possibilites[i].push_back(num);
                int another = num / i;
                if(another != i) possibilites[another].push_back(num);
            }
        }
    }
    
    int getGCD(long long posi, vector<pair<int, long long>>& gcds){
        int i = 0, j = gcds.size() - 1;
        while(i < j){
            int mid = (i + j) / 2;
            if(gcds[mid].second >= posi){
                if(mid > 0 and gcds[mid - 1].second >= posi) j = mid - 1;
                else return gcds[mid].first;
            }
            else{
                i = mid + 1;
            }
        }
        return gcds[i].first; 
    }
    
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<vector<int>>possibilites(maxi + 1);
        for(auto i : nums) findFactors(i, possibilites);
        vector<pair<int, long long>>gcds;
        vector<long long> exact(maxi + 1, 0); 
        for(int i = maxi; i >= 1; i--){
            long long c = possibilites[i].size();
            if(c > 1){
                long long total = (c * (c - 1)) / 2;
                for(int mult = 2 * i; mult <= maxi; mult += i){
                    total -= exact[mult];
                }
                exact[i] = total;
                if(total > 0){
                    gcds.push_back({i, total});
                }
            }
        }
        
        reverse(gcds.begin(), gcds.end());
        long long runningTotal = 0;
        for(int i = 0; i < gcds.size(); i++){
            runningTotal += gcds[i].second;
            gcds[i].second = runningTotal;
        }

        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++){
            int val = getGCD(queries[i] + 1, gcds);
            ans[i] = val;
        }
        return ans;
    }
};