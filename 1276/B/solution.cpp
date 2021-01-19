#include<bits/stdc++.h>

using namespace std;
const int maxm = 2e5 + 10;
int n, m, a, b;
vector<int> son[maxm];
bool vis[maxm];

void defer() {/*{{{*/
    for (int i = 0; i <= n; i++) {
        son[i].clear();
    }
}/*}}}*/
void dfs(int start = a) {/*{{{*/
    vis[start] = true;
    for (auto i : son[start]) {
        if (vis[i] || i == b) continue;
        dfs(i);
    }
}/*}}}*/
void solve() {
    cin >> n >> m >> a >> b;
    for (int i = 0, from, to; i < m; i++) {
        cin >> from >> to;
        son[from].push_back(to);
        son[to].push_back(from);
    }
    dfs();
    int cnt1 = -1, cnt2 = -1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) vis[i] = false;
        else cnt1++;
    }
    swap(a, b);
    dfs();
    for (int i = 1; i <= n; i++) {
        if (vis[i]) vis[i] = false;
        else cnt2++;
    }
    cout << 1ll * cnt1 * cnt2 << endl;
    defer();
}

int main() {
#ifdef DEBUG
    freopen("./1276/B/in", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

