#include<bits/stdc++.h>

using namespace std;
const int maxm = 1e5 + 10;
int n;
int num[maxm];
long long pre_sum[maxm];
long long ans[maxm];

int main() {
#ifdef DEBUG
    freopen("./226/B/in", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> num[i];
    sort(num + 1, num + n + 1);
    for (int i = 1; i <= n; i++) pre_sum[i] = pre_sum[i - 1] + num[i];
    for (int i = 1; i <= 1e5; i++) { // step len;
        long long buffer = 1, len = i;
        for (long long r = n - 1; r >= 1; buffer++) {
            int l = max(r - len, 0ll);
            ans[i] += buffer * (pre_sum[r] - pre_sum[l]);
            r -= len;
            len *= i;
        }
    }
    int q, que;
    cin >> q;
    while (q--) {
        cin >> que;
        cout << ans[que] << ' ';
    }
    return 0;
}

