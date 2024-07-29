#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-ffloat-store")
#pragma GCC optimize("Ofast")

static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define frw(i, len) for(int i = 0; i < len; i++)
#define frb(i, len) for(int i = len; i >= 0; i--)

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
int size_stack = 0;
int InvrsnCnt = 0;
int size_arr = 0;
int size_ll = 0;
int top = -1;

int INF = 1e10 + 10;
c_int N = 1e5 + 10;
vector<pair<int, int>> g[N];
vint lvl(N, INF);
int n, m;

void bfs(int src) {
    deque<int> q;
    q.push_back(src);
    lvl[src] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop_front();

        for (auto child : g[curr]) {
            int CurrChld = child.first;
            int wgt = child.second;
            if (lvl[curr] + wgt < lvl[CurrChld]) {
                lvl[CurrChld] = lvl[curr] + wgt;
                if (wgt) {
                    q.push_back(CurrChld);
                } else {
                    q.push_front(CurrChld);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});  
    }
    bfs(1);
    for (int i = 1; i <= n; i++) {
        if (lvl[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Level of node " << i << " is " << lvl[i] << "\n";
        }
    }    
    return 0;
}
