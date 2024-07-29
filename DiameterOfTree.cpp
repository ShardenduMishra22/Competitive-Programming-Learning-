#include <bits/stdc++.h>
using namespace std;

static auto _ = []() {
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
vint Dpth(N, 0);

void dfs(int vrtx, int prnt) {
    for(int child : g[vrtx]) {
        if(child == prnt) continue;
        Dpth[child] = Dpth[vrtx] + 1;
        dfs(child, vrtx);
    }
}

int main() {
    int Nodes; cin >> Nodes;
        
    frw(0, Nodes - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Initialize depth for root node
    Dpth[1] = 0; 
    dfs(1, 0);

    int MxDpth = -1;
    int MxDpthNode = 1;  // Initialize with a valid node index

    frw(1, Nodes + 1) {
        if(MxDpth < Dpth[i]) {
            MxDpth = Dpth[i];
            MxDpthNode = i;
        }
    }

    // Reset Dpth for second DFS
    fill(Dpth.begin(), Dpth.begin() + Nodes + 1, 0);
    
    Dpth[MxDpthNode] = 0;  // Initialize depth for the new root node
    dfs(MxDpthNode, 0);

    frw(1, Nodes + 1) {
        if(MxDpth < Dpth[i]) {
            MxDpth = Dpth[i];
            MxDpthNode = i;
        }
    }

    cout << "Farthest Node from the maximum depth node: " << MxDpthNode << endl;
    cout << "Maximum Depth from the new root node: " << MxDpth << endl;

    return 0;
}
