#include<bits/stdc++.h>

using namespace std;
const int maxm = 1e6 + 10;
int n;
vector<int> son[maxm];
int p[maxm];
int buffer[maxm];

long long dfs2(int a) {
    long long ret = 1;
    p[a] = 1;
    for (auto i : son[a]) {
        if (p[i]) continue;
        ret += dfs2(i);
    }
    return ret;
}

void dfs1(int i = 1, int pre = 1) {/*{{{*/
    p[i] = pre;
    if (buffer[0] != 0) return;
    for (auto j : son[i]) {
        if (j == pre) continue;
        if (p[j] != 0 && buffer[0] == 0) { // on loop
            buffer[++buffer[0]] = j;
            int now = i;
            while (now != j) {
                buffer[++buffer[0]] = now;
                now = p[now];
            }
            return;
        }
        dfs1(j, i);
    }
}/*}}}*/
void solve() {
    cin >> n;
    for (int i = 0, from, to; i < n; i++) {
        cin >> from >> to;
        son[from].push_back(to);
        son[to].push_back(from);
    }
    dfs1();
    for (int i = 1; i <= n; i++) p[i] = 0;
    for (int i = 1; i <= buffer[0]; i++) p[buffer[i]] = 1;
    long long ans = 1ll * n * (n - 1);
    for (int i = 1; i <= buffer[0]; i++) {
        auto cnt = dfs2(buffer[i]);
        ans -= cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;
    buffer[0] = 0;
    for (int i = 1; i <= n; i++) son[i].clear(), p[i] = 0;
}

int main() {
#ifdef DEBUG
    freopen("./1454/E/in", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

