#include <bits/stdc++.h>
using namespace std;

static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

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
c_int N = 1e3 + 10;
vector<pair<int, int>> g[N];

int lvl[N][N];
int vis[N][N];
int val[N][N];

vector<pair<int, int>> MvMnt = {{0, 1}, {0, -1}, {1, 0}, { -1, 0 }};

void Reset() {
    for (int i = 0; i < N; i += 1) {
        for (int j = 0; j < N; j += 1) {
            vis[i][j] = 0;
            lvl[i][j] = INF;
        }
    }
}

bool IsValid(int i, int j) {
    return (i >= 0 && j >= 0 && i < N && j < N);
}

int bfs() {
    queue<pair<int,int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (val[i][j] == 1) {
                q.push({i, j});
                lvl[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }

    while (!q.empty()) {
        auto v = q.front();
        int vX = v.first;
        int vY = v.second;
        q.pop();

        for (auto mve : MvMnt) {
            int chldX = vX + mve.first;
            int chldY = vY + mve.second;

            if (!IsValid(chldX, chldY)) continue;
            if (vis[chldX][chldY]) continue;

            q.push({chldX, chldY});
            lvl[chldX][chldY] = lvl[vX][vY] + 1;
            vis[chldX][chldY] = 1;
        }
    }

    int mx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lvl[i][j] != INF) {
                mx = max(mx, lvl[i][j]);
            }
        }
    }

    return mx;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> val[i][j];
        }
    }

    Reset();
    cout << bfs() << endl;

    return 0;
}
