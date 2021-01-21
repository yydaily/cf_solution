#include<bits/stdc++.h>

using namespace std;
const int mod = 998244353;

int add(int a, int b) { return (a + b) % mod; }

int mul(long long a, long long b) { return (a * b) % mod; }

int handler() {
    int a;
    cin >> a;
    int ret = 0;
    int base = 1;
    while (a) {
        ret = add(ret, mul(base, a % 10));
        base = mul(base, 100);
        a /= 10;
    }
    return mul(ret, 11);
}

int main() {
#ifdef DEBUG
    freopen("./1195/D1/in", "r", stdin);
#endif
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, handler());
    }
    cout << mul(ans, n) << endl;
    return 0;
}

