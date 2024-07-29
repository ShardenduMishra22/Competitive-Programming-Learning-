#include <bits/stdc++.h>
using namespace std;

static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define frw(i, len) for(ll i = 0 ; i < len ; i++)

typedef long long int ll;
#define MAX_SIZE 1000000

int n;
ll m;
ll trees[MAX_SIZE];

bool IsWoodSufficient(int h) {
    ll wood = 0;
    for (int i = 0; i < n; i++) {
        if (trees[i] > h) {
            wood += (trees[i] - h);
        }
    }
    return wood >= m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }

    ll low = 0, high = *max_element(trees, trees + n);
    ll best_height = 0;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (IsWoodSufficient(mid)) {
            best_height = mid; 
            low = mid + 1;     
        } else {
            high = mid - 1;  
        }
    }

    cout << best_height << "\n";
    return 0;
}
