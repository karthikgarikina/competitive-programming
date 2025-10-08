#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; 
        }

        bool flag = false, ans = true;
        int idx = 0;

        while (idx < n) {
            if (arr[idx] == 1) flag = true;
            if (flag) x--;
            idx++;
            if (x == 0) break;
        }

        while (idx < n) {
            if (arr[idx] == 1) {
                ans = false;
                break;
            }
            idx++;
        }

        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
