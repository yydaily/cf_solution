#include<bits/stdc++.h>

using namespace std;
const int maxm = 1e6 + 10;
int n;
map<int, int> m[2];

int main() {
#ifdef DEBUG
    freopen("./1109/A/in", "r", stdin);
#endif
    cin >> n;
    int last = 0;
    long long ans = 0;
    m[0][0] = 1;
    for (int i = 1, now; i <= n; i++) {
        cin >> now;
        last ^= now;
        ans += m[i & 1][last];
        m[i & 1][last]++;
//        cout << "m[" << (i & 1) << "][" << now << "]=" << m[i & 1][now] << endl;
    }
    cout << ans << endl;
    return 0;
}

