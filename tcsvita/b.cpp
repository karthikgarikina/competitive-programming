#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const std::pair<int, long long> INF_PAIR = {INF_INT, INF_LL};

struct State {
    int len, link;
    std::unordered_map<char, int> next;
};

class SuffixAutomaton {
public:
    std::vector<State> states;
    int last;

    SuffixAutomaton() {
        states.emplace_back(State{0, -1, {}});
        last = 0;
    }

    void extend(char c) {
        int new_state_idx = states.size();
        states.emplace_back(State{states[last].len + 1, -1, {}});

        int p = last;
        while (p != -1 && states[p].next.find(c) == states[p].next.end()) {
            states[p].next[c] = new_state_idx;
            p = states[p].link;
        }

        if (p == -1) {
            states[new_state_idx].link = 0;
        } else {
            int q = states[p].next[c];
            if (states[q].len == states[p].len + 1) {
                states[new_state_idx].link = q;
            } else {
                int clone_idx = states.size();
                states.emplace_back(State{states[p].len + 1, states[q].link, states[q].next});
                
                while (p != -1 && states[p].next[c] == q) {
                    states[p].next[c] = clone_idx;
                    p = states[p].link;
                }
                states[q].link = clone_idx;
                states[new_state_idx].link = clone_idx;
            }
        }
        last = new_state_idx;
    }
};

SuffixAutomaton build_sa(const std::string& text) {
    SuffixAutomaton sa;
    for (char c : text) {
        sa.extend(c);
    }
    return sa;
}

std::vector<int> compute_L(SuffixAutomaton& sa, const std::string& x_string) {
    int n = x_string.length();
    std::vector<int> L(n + 1, 0);

    int v = 0;
    int l = 0;

    for (int i = 0; i < n; ++i) {
        char c = x_string[i];
        while (v != 0 && sa.states[v].next.find(c) == sa.states[v].next.end()) {
            v = sa.states[v].link;
            l = sa.states[v].len;
        }

        if (sa.states[v].next.count(c)) {
            v = sa.states[v].next.at(c);
            l++;
        }
        L[i + 1] = l;
    }
    return L;
}

class SegTree {
private:
    int n;
    std::vector<std::pair<int, long long>> tree;

    void _update(int node, int start, int end, int idx, std::pair<int, long long> val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (start <= idx && idx <= mid) {
            _update(2 * node, start, mid, idx, val);
        } else {
            _update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = std::min(tree[2 * node], tree[2 * node + 1]);
    }
    
    std::pair<int, long long> _query(int node, int start, int end, int l, int r) {
        if (r < start || end < l || l > r) {
            return INF_PAIR;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        auto p1 = _query(2 * node, start, mid, l, r);
        auto p2 = _query(2 * node + 1, mid + 1, end, l, r);
        return std::min(p1, p2);
    }

public:
    SegTree(int size) : n(size) {
        tree.assign(4 * n, INF_PAIR);
    }

    void update(int idx, std::pair<int, long long> val) {
        _update(1, 0, n - 1, idx, val);
    }

    std::pair<int, long long> query(int l, int r) {
        if (l > r) return INF_PAIR;
        return _query(1, 0, n - 1, l, r);
    }
};

void solve() {
    std::string X, Y;
    std::cin >> X >> Y;
    long long S, R;
    std::cin >> S >> R;

    int n = X.length();
    if (n == 0) {
        std::cout << 0 << "\n";
        return;
    }

    std::string Y_rev = Y;
    std::reverse(Y_rev.begin(), Y_rev.end());
    
    SuffixAutomaton sa_Y = build_sa(Y);
    SuffixAutomaton sa_Y_rev = build_sa(Y_rev);
    
    std::vector<int> L_Y = compute_L(sa_Y, X);
    std::vector<int> L_Y_rev = compute_L(sa_Y_rev, X);

    SegTree seg_tree(n + 1);
    seg_tree.update(0, {0, 0});

    for (int i = 1; i <= n; ++i) {
        auto dp_i = INF_PAIR;

        int l_s = L_Y[i];
        if (l_s > 0) {
            auto prev_min_s = seg_tree.query(i - l_s, i - 1);
            if (prev_min_s.first != INF_INT) {
                std::pair<int, long long> cand_s = {prev_min_s.first + 1, prev_min_s.second + S};
                dp_i = std::min(dp_i, cand_s);
            }
        }
        
        int l_r = L_Y_rev[i];
        if (l_r > 0) {
             auto prev_min_r = seg_tree.query(i - l_r, i - 1);
            if (prev_min_r.first != INF_INT) {
                std::pair<int, long long> cand_r = {prev_min_r.first + 1, prev_min_r.second + R};
                dp_i = std::min(dp_i, cand_r);
            }
        }

        if (dp_i.first != INF_INT) {
            seg_tree.update(i, dp_i);
        }
    }

    auto final_dp = seg_tree.query(n, n);
    if (final_dp.first == INF_INT) {
        std::cout << "Impossible\n";
    } else {
        std::cout << final_dp.second << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}