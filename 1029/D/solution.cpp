#include<bits/stdc++.h>

using namespace std;
const int maxm = 2e5 + 10;
int n, mod;
int num[maxm];
vector<int> m[11];
int len[maxm];

int get_len(int a) {
    int ret = 0;
    while (a) {
        ret++;
        a /= 10;
    }
    return ret;
}

int cal(int buffer, int ind) {
    if (buffer == mod) buffer = 0;
    auto l = lower_bound(m[ind].begin(), m[ind].end(), buffer);
    auto r = upper_bound(m[ind].begin(), m[ind].end(), buffer);
    return r - l;
}

int main() {
#ifdef DEBUG
    freopen("./1029/D/in", "r", stdin);
#endif
    cin >> n >> mod;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        long long now = num[i];
        len[i] = get_len(num[i]);
        for (int j = 1; j <= 10; j++) {
            now = (now * 10) % mod;
            m[j].push_back(now);
            if (j == len[i]) {
                ans -= (now + num[i]) % mod == 0;
            }
        }
    }
    for (int i = 0; i <= 10; i++) sort(m[i].begin(), m[i].end());


    for (int i = 0; i < n; i++) {
//        cout << cal(mod - num[i] % mod, len[i]) << endl;
        ans += cal(mod - num[i] % mod, len[i]);
    }
    cout << ans << endl;
    return 0;
}

