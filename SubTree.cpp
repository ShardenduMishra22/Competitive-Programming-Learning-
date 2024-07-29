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
int size_stack = 0;
int InvrsnCnt = 0;
int size_arr = 0;
int size_ll = 0;
int top = -1;

c_int N = 1e5 + 10;
vint g[N];
vbl Prime(N + 1, true);

void isPrime() {
    Prime[0] = Prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (Prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                Prime[j] = false;
            }
        }
    }
}

void dfs(int vrtx, int prnt, vint& SubTree, vint& OddCount, vint& EvenCount, vint& PrimeCount) {
    SubTree[vrtx] = vrtx;
    if (vrtx & 1) OddCount[vrtx] = 1;
    else EvenCount[vrtx] = 1;
    if (Prime[vrtx]) PrimeCount[vrtx] = 1;

    for (auto child : g[vrtx]) {
        if (child == prnt) continue;
        dfs(child, vrtx, SubTree, OddCount, EvenCount, PrimeCount);
        SubTree[vrtx] += SubTree[child];
        OddCount[vrtx] += OddCount[child];
        EvenCount[vrtx] += EvenCount[child];
        PrimeCount[vrtx] += PrimeCount[child];
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

    isPrime();

    vint SubtreeSum(Nodes + 1, 0);
    vint OddCount(Nodes + 1, 0);
    vint EvenCount(Nodes + 1, 0);
    vint PrimeCount(Nodes + 1, 0);

    dfs(1, 0, SubtreeSum, OddCount, EvenCount, PrimeCount);

    frw(1, Nodes + 1) {
        cout << "Node " << i << ":\n";
        cout << "Subtree sum: " << SubtreeSum[i] << "\n";
        cout << "Odd count: " << OddCount[i] << "\n";
        cout << "Even count: " << EvenCount[i] << "\n";
        cout << "Prime count: " << PrimeCount[i] << "\n";
        nl
    }
    return 0;
}
