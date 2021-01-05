#include<bits/stdc++.h>

using namespace std;
const int maxm = 1e5 + 10;
int n, x;
vector<int> num, num2;

int main() {
#ifdef DEBUG
    freopen("./1151/E/in", "r", stdin);
#endif
    cin >> n;
    num.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        num.push_back(x);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        // num[i] exists but num[i-1] not exists
        if (num[i] > num[i - 1]) {
            // l range : [num[i-1]+1, num[i]]
            // r range : [num[i], n]
            ans += 1ll * (num[i] - num[i - 1]) * (n - num[i] + 1);
        } else {
            // l range : [1, num[i]]
            // r range : [num[i], num[i-1]-1]
            ans += 1ll * num[i] * (num[i - 1] - num[i]);
        }
    }
    cout << ans << endl;
    return 0;
}

