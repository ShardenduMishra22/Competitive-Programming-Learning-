#include <bits/stdc++.h>
using namespace std;

static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

typedef long long int ll;
typedef vector<int> vint;

int main() {
    int n;
    cin >> n;
    vint PrimeFactor;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            PrimeFactor.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        PrimeFactor.push_back(n);
    }
    for (auto i : PrimeFactor) {
        cout << i << " ";
    }
    return 0;
}

// int main(){
//     int n;cin>>n;
//     bool IsPrime = true;
//     for(int i=2;i*i<=n;i++){
//         if(n % i == 0){
//             IsPrime = false;
//             break;
//         }
//     }
//     cout<<IsPrime<<endl;
//     return 0;
// }
