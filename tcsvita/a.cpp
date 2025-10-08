#include<bits/stdc++.h>
using namespace std;

bool isValid(int r, int c, int M, int N, const vector<vector<int>>& grid, const vector<vector<int>>& dist) {

    if (r < 0 || r >= M || c < 0 || c >= N) {
        return false;
    }
    if (grid[r][c] == 1) {
        return false;
    }
    if (dist[r][c] != -1) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    int srcR, srcC;
    cin >> srcR >> srcC;

    int destR, destC;
    cin >> destR >> destC;

    int moveX, moveY;
    cin >> moveX >> moveY;

    if (grid[srcR][srcC] == 1 || grid[destR][destC] == 1) {
        cout << -1 << endl;
        return 0;
    }
    if (srcR == destR && srcC == destC) {
        cout << 0 << endl;
        return 0;
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(M, vector<int>(N, -1));

    q.push({srcR, srcC});
    dist[srcR][srcC] = 0; 

    int dr[] = {moveX, moveY, -moveY, -moveX}; 
    int dc[] = {moveY, -moveX, moveX, -moveY};

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int r = curr.first;
        int c = curr.second;

        for (int i = 0; i < 4; ++i) {
            int nextR = r + dr[i];
            int nextC = c + dc[i];

            if (isValid(nextR, nextC, M, N, grid, dist)) {
                dist[nextR][nextC] = dist[r][c] + 1;

                if (nextR == destR && nextC == destC) {
                    cout << dist[nextR][nextC] << endl;
                    return 0;
                }

                q.push({nextR, nextC});
            }
        }
    }
    cout << dist[destR][destC] << endl;

    return 0;
}
