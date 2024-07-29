#include <bits/stdc++.h>
using namespace std;

static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define frw(i, len) for(int i=0; i < len ; i++)
#define frb(i, len) for(int i=len; i >= 0; i--)

#define YES cout<<"Yes \n";
#define NOO cout<<"No  \n";
#define nl cout<<"\n";

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

c_int MOD=1e9 + 7;
c_int Mx_row=100;
c_int Mx_col=100;
int size_stack=0;
int InvrsnCnt=0;
int size_arr=0;
int size_ll=0;
int top=-1;

c_int N = 1e5 + 10;
vector<vector<pair<int, int>>> g(N);

void dijkstra(int src){
    vint vis(N, 0);
    vint dst(N, INT_MAX);

    set<pair<int, int>> st;
    st.insert({0, src});
    dst[src] = 0;

    while(!st.empty()){
        auto node = *st.begin();
        st.erase(st.begin());

        int curr_dst = node.first; 
        int v = node.second;
        if(vis[v]) continue;
        vis[v] = 1;

        for(auto child : g[v]){
            int CurrChild = child.first;
            int wt = child.second;
            if(curr_dst + wt < dst[CurrChild]){
                dst[CurrChild] = curr_dst + wt;
                st.insert({dst[CurrChild], CurrChild});
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }

    int src;
    cin >> src;
    dijkstra(src);

    return 0;
}
