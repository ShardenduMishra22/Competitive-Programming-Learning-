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
vbl Prime(N,true);
vint HgstPrime(N,0),LwstPrime(N,0);
vint PrimeFactor;

int main(){
    Prime[0] = Prime[1] = false;
    for(int i=2;i<N;i++){
        if(Prime[i] == true){
            HgstPrime[i] = LwstPrime[i] = i;
            for(int j=2*i;j<N;j+=i){
                Prime[j] = false;
                HgstPrime[j] = i;
                if(!LwstPrime[j]){
                    LwstPrime[j] = i;
                }
            }
        }
    }
    int Num;cin>>Num;
    while(Num > 1){
        int pf = HgstPrime[Num];
        while (Num % pf == 0){
            Num /= pf;
            PrimeFactor.push_back(pf);
        }
    }
    for(auto i : PrimeFactor){
        cout<<i<<" ";
    }
}