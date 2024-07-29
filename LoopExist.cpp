#include <bits/stdc++.h>
using namespace std;

#pragma GCC target   ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("Ofast")

static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define frw(i, len) for(ll i = 0   ; i < len ; i++)
#define frb(i, len) for(ll i = len ; i >= 0  ; i--)

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
vint g[N];
vbl vis(N,false);

bool dfs(int vrtx,int par){
    bool IsLoop = false;
    vis[vrtx] = true;
    for(auto child : g[vrtx]){
        if(vis[child] && child == par){
            continue;
        }
        if(vis[child]){
            return true;
        }
        IsLoop |= dfs(child,vrtx);
    }
    return IsLoop;
}

int main(){
    int Nodes,Edges;
    cin>>Nodes>>Edges;
    for (int i=0;i<Edges;i++){
        int v,u;
        cin>>v>>u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    bool IsLoop = false;
    int cnt = 0;
    for(int i=1;i<Nodes;i++){
        if(vis[i]){
            continue;
        }
        if(dfs(i,0)){
            IsLoop = true;
            break;
        }
        cnt += 1;
    }
    if(IsLoop){
        cout<<"Loop Exists";
    }else{
        cout<<"No Loop";
    }
    return 0;
}