#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, mx = 0;
        cin >> a;
        cin.ignore();
        string str;
        getline(cin, str);
        int stpr = -1;
        for (int i = 0; i < a; i++) {
            if (str[i] == 'A') {
                stpr = 0;
                for (int j = i + 1; j < str.size(); j++) {
                    if(str[j] == 'P') {
                        stpr += 1;
                    }else{
                        break;
                    }
                }
            }
            mx = max(stpr, mx);
        }
        cout<<mx<<"\n";
    }
    return 0;
}