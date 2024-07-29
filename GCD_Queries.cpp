// #include <bits/stdc++.h>
// using namespace std;

// #pragma GCC target   ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("-ffloat-store")
// #pragma GCC optimize ("Ofast")

// static auto _ = [] () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 0;
// }();

// #define frw(i, len) for(int i=0; i < len ; i++)
// #define frb(i, len) for(int i=len; i >= 0; i--)

// #define YES cout<<"Yes \n";
// #define NOO cout<<"No  \n";
// #define nl cout<<"\n";

// #define MAX_SIZE 10000
// #define nptr nullptr

// typedef stringstream strgm;
// typedef long long int ll;
// typedef const int c_int;
// typedef unsigned unsg;
// typedef double dbl;

// typedef vector<vector<string>> vvstr;
// typedef vector<vector<bool>> vvbl;
// typedef vector<vector<int>> vvint;
// typedef vector<vector<ll>> vvll;

// typedef vector<string> vstr;
// typedef vector<int> vint;
// typedef vector<bool> vbl;
// typedef vector<ll> vll;

// typedef stack<string> sstr;
// typedef stack<bool> sbl;
// typedef stack<int> sint;
// typedef stack<ll> sll;

// typedef queue<string> qstr;
// typedef queue<bool> qbl;
// typedef queue<int> qint;
// typedef queue<ll> qll;

// c_int MOD=1e9 + 7;
// c_int Mx_row=100;
// c_int Mx_col=100;
// int size_stack=0;
// int InvrsnCnt=0;
// int size_arr=0;
// int size_ll=0;
// int top=-1;


// int main() {

//     int t;
//     cin >> t;
    
//     while(t--) {
//         int n, q;
//         cin >> n >> q;
//         int arr[n + 1]; 
//         for(int i = 1; i <= n; i++) {
//             cin >> arr[i];
//         }
//         while(q--) {
//             int l, r;
//             cin >> l >> r;
//             int gc = 0;
//             for(int i = 1; i <= n; i++) {
//                 if(i < l || i > r) { 
//                     gc = __gcd(gc, arr[i]);
//                 }
//             }            
//             cout << gc << "\n";
//         }
//     }
    
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    
    while(t--) {
        int n, q;
        cin >> n >> q;
        
        int arr[n + 1];
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        
        int gcd_forward[n + 1];
        gcd_forward[0] = 0; 
        
        for(int i = 1; i <= n; i++) {
            gcd_forward[i] = __gcd(gcd_forward[i - 1], arr[i]);
        }
        
        int gcd_backward[n + 2];
        gcd_backward[n + 1] = 0; 
        
        for(int i = n; i >= 1; i--) {
            gcd_backward[i] = __gcd(gcd_backward[i + 1], arr[i]);
        }
        
        while(q--) {
            int l, r;
            cin >> l >> r;
            int gc = __gcd(gcd_forward[l - 1], gcd_backward[r + 1]);
            
            cout << gc << "\n";
        }
    }
    
    return 0;
}
