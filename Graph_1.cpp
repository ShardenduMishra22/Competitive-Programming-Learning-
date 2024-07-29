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

c_int N = 1e3;
int Grph1[N][N];
vector<vector<pair<int,int>>> Grph2(N);

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int t1,t2,wt;
        cin>>t1>>t2>>wt;

        Grph1[t1][t2] = wt;
        Grph1[t2][t1] = wt;
    }
    for(int i =0;i<m;i++){
        int t1,t2,wt;
        cin>>t1>>t2>>wt;

        Grph2[t1].push_back({t2,wt});
        Grph2[t2].push_back({t1,wt});
    }
    int edg1,edg2;
    cin>>edg1>>edg2;
    
    // check if there is an edge matrix
    // O(1) 
    if(Grph1[edg1][edg2]){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    bool found = false;
    for (auto i : Grph2[edg1]) {
        if (i.first == edg2) {
            cout << "Yes\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No\n";
    }
}