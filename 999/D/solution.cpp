#include<bits/stdc++.h>

using namespace std;
const int maxm = 2e6 + 10; // todo xzn
int n, m;
struct p {
    int val;
    int realVal;
    int ind;
};
p num[maxm];
int cnt[maxm];

bool cmp(p a, p b) {
    return a.val < b.val;
}

bool cmp2(p a, p b) {
    return a.ind < b.ind;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i].realVal, num[i].val = num[i].realVal % m, num[i].ind = i, cnt[num[i].val]++;
    sort(num, num + n, cmp);

    long long ans = 0;
    int r = 1;
    for (int i = 0; i < n; i++) {
        r = max(r, num[i].val + 1);
        if (cnt[num[i].val] > n / m) {
            while (cnt[r] >= n / m) r++;
            if (r == m) break;
            cnt[num[i].val]--;
            cnt[r]++;
            ans += r - num[i].val;
            num[i].realVal += r - num[i].val;
        }
    }

    r = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (cnt[num[i].val] > n / m) {
            while (cnt[r] >= n / m) r++;
            cnt[num[i].val]--;
            cnt[r]++;
            ans += r + m - num[i].val;
            num[i].realVal += r + m - num[i].val;
        }
    }

    sort(num, num + n, cmp2);
    cout << ans << endl;
    for (int i = 0; i < n; i++) cout << num[i].realVal << ' ';
    cout << endl;
    return 0;
}

