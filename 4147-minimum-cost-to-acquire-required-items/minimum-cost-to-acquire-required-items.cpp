class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mini = min(need1, need2), ans = 0;
        if(cost1 + cost2 > costBoth){
            ans += (1LL * mini * costBoth);
            need1 -= mini, need2 -= mini;
        }
        if(cost1 > costBoth) ans += (1LL * need1 * costBoth);
        else ans += (1LL * need1 * cost1);
        if(cost2 > costBoth) ans += (1LL * need2 * costBoth);
        else ans += (1LL * need2 * cost2);

        return ans;
    }
};