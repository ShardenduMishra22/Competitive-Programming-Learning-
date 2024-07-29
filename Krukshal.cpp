#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 10000
typedef long long int ll;
typedef const int c_int;

c_int N = 1e5 + 10;
int prnt[N], size[N];

void make(int v) {
    prnt[v] = v;
    size[v] = 1;
}

int find(int v) {
    if (prnt[v] == v) {
        return v;
    }
    return prnt[v] = find(prnt[v]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (size[a] < size[b]) {
            swap(a, b);
        }
        prnt[b] = a;
        size[a] += size[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    // Initialize Union-Find data structure
    for (int i = 0; i < n; i++) {
        make(i);
    }

    vector<pair<int, pair<int, int>>> Edges;
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        Edges.push_back({wt, {u, v}});
    }

    int TotalCost = 0;
    sort(Edges.begin(), Edges.end());

    for (auto& edge : Edges) {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (find(u) != find(v)) {
            Union(u, v);
            TotalCost += wt;
            cout << u << " " << v << "\n";
        }
    }

    cout << TotalCost << "\n";
    return 0;
}