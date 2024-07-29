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

c_int N = 1e5+10;
vvint vis(8, vint(8, 0));
vvint lvl(8, vint(8, 0));

int GetX(string s) {
    return s[0]-'a';
}

int GetY(string s) {
    return s[1]-'1';
}

bool IsValid(int x, int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

vector<pair<int,int>> MvMnt = {{-1,-2},{-1,2},
                              {1,2},{1,-2},
                              {2,-1},{2,1},
                              {-2,-1},{-2,1}};

int bfs(string src, string dst) {
    int srcX = GetX(src);
    int srcY = GetY(src);
    int dstX = GetX(dst);
    int dstY = GetY(dst);

    queue<pair<int,int>> q;
    q.push({srcX, srcY});
    vis[srcX][srcY] = 1;

    while(!q.empty()){
        pair<int,int> v = q.front();
        int x = v.first, y = v.second;
        q.pop();
        
        if(x == dstX && y == dstY) {
            return lvl[x][y];
        }

        for(auto move : MvMnt){
            int chldX = move.first + x;
            int chldY = move.second + y;
            if(!IsValid(chldX,chldY)){
                continue;
            }
            if(vis[chldX][chldY]){
                continue;
            }
            q.push({chldX,chldY});
            vis[chldX][chldY] = 1;
            lvl[chldX][chldY] = lvl[x][y] + 1;
        }        
    }

    return -1;
}

int main() {
    string src, dst;
    cin >> src >> dst;
    int result = bfs(src, dst);
    cout << "Minimum moves: "<<result<<"\n";
    return 0;
}
