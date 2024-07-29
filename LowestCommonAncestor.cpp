#include <bits/stdc++.h>
using namespace std;

static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define frw(start, end) for(ll i = start; i < end; i++)
#define frb(start, end) for(ll i = end; i >= start; i--)

#define YES cout << "Yes \n";
#define NOO cout << "No  \n";
#define nl cout << "\n";

#define MAX_SIZE 10000
#define nptr nullptr

typedef stringstream strgm;
typedef long long int ll;
typedef const int c_int;
typedef unsigned unsg;
typedef double dbl;

typedef vector<vector<string>> vvstr;
typedef vector<vector<bool>> vvbl;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvll;

typedef vector<string> vstr;
typedef vector<int> vint;
typedef vector<bool> vbl;
typedef vector<ll> vll;

typedef stack<string> sstr;
typedef stack<bool> sbl;
typedef stack<int> sint;
typedef stack<ll> sll;

typedef queue<string> qstr;
typedef queue<bool> qbl;
typedef queue<int> qint;
typedef queue<ll> qll;

c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;

c_int N = 1e5 + 10;
vint g[N];
vector<int> parent(N, 0);  // Track parent of each node
vector<int> depth(N, 0);    // Track depth of each node

void dfs(int vrtx, int prnt) {
    parent[vrtx] = prnt;
    for(int child : g[vrtx]) {
        if(child == prnt) continue;
        depth[child] = depth[vrtx] + 1;
        dfs(child, vrtx);
    }
}

vint path(int node) {
    vint p;
    while (node != 0) {
        p.push_back(node);
        node = parent[node];
    }
    reverse(p.begin(), p.end());
    return p;
}

int findLCA(int x, int y) {
    vint pathX = path(x);
    vint pathY = path(y);
    int lca = 0;

    // Iterate through both paths to find the common ancestor
    int i = 0;
    int j = 0;
    while (i < pathX.size() && j < pathY.size() && pathX[i] == pathY[j]) {
        lca = pathX[i];
        i++;
        j++;
    }
    return lca;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(1, 0);  // Start DFS from node 1 with no parent (0)

    int x, y;
    cin >> x >> y;
    
    vint PathX = path(x);
    vint PathY = path(y);

    // Find and print the LCA
    int lca = findLCA(x, y);

    // Output the paths
    cout << "Path from root to " << x << ": ";
    for(int node : PathX) cout << node << " ";
    cout << "\n";

    cout << "Path from root to " << y << ": ";
    for(int node : PathY) cout << node << " ";
    cout << "\n";

    cout << "Lowest Common Ancestor of " << x << " and " << y << ": " << lca << endl;

    return 0;
}
