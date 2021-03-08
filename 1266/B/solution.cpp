#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a;
        cin >> a;
        if(a<14) {
            puts("NO");
            continue;
        }
        bool vis = false;
        for (int i = 1; i <= 6; i++) {
            if ((a - i) % 14 == 0) {
                puts("YES");
                vis = true;
            }
        }
        if (!vis) {
            puts("NO");
        }
    }
    return 0;
}
