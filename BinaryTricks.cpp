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

void PrntBnry(int n){
    for(int i = 10;i >= 0;i--){
        cout<<((n>>i)&1);
    }
    nl;
}

int SetBit(int a,int i){
    return ((1<<i) | a);
}

int UnSetBit(int a,int i){
    return ((~(1<<i))&a);
}

int GetBit(int a,int i){
    return ((1<<i) & a);
}

int Toggle(int a,int i){
    return ((1<<i) ^ a);
}

int ClearMSB(int a,int i){
    // PrntBnry((~((1<<(i+1))-1))); // 4
    return ((~((1<<(i+1))-1)) & a);
}

int main(){
    int a = 9;   
    // PrntBnry(a);

    // Set Bit
    int b,i = 2;
    b = SetBit(a,i); // should be 13
    // cout<<b;nl;
    // PrntBnry(b);

    // Get Bit
    i = 0;
    // cout<<((GetBit(a,i) == 1) ? "Bit is Set" : "Bit is not Set");nl;

    // UnSetting a Bit
    i=3;
    int d = UnSetBit(a,i);
    // PrntBnry(d);

    // Toggle a bit
    i = 1;
    int e = Toggle(a,i);
    // cout<<e;nl;

    // count no of bits
    int f = 8;
    // cout<<__builtin_popcount(f);nl;

    ll g = 1LL<<35;
    // cout<<__builtin_popcountll(g);nl;

    char c1 = 'A';
    // cout<<(char)(c1 | ' ');nl;

    char c2 = 'a';
    // cout<<(char)(c2 & '_');nl;

    int h = 59;
    // PrntBnry(h); // 1
    // PrntBnry(h);
    i = 4;
    int one = ClearMSB(h,i);
    // PrntBnry(one); // 3
    cout<<one;nl; // 4
    
    int j = 16;
    if(!(j&(j-1))){
        cout<<"Power of two";nl;
    }else{
        cout<<"Not a Power of two";nl;
    }

    return 0;
}

// int main(){
//     PrntBnry(1<<5);
// }