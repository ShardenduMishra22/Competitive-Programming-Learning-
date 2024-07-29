#include <bits/stdc++.h>
using namespace std;

static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

typedef long long int ll;
typedef const int c_int;
typedef vector<int> vint;
typedef queue<int> qint;

c_int MOD = 1e9 + 7;
c_int N = 1e5 + 10;
vint g[N];
vint vis(N);
vint lvl(N);

void bfs(int src) {
    qint q;
    q.push(src);
    vis[src] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int child : g[curr]) {
            if (vis[child]) continue;
            q.push(child);
            vis[child] = 1;
            lvl[child] = lvl[curr] + 1;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " Level: " << lvl[i] << "\n";
    }

    return 0;
}
