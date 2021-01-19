#include<bits/stdc++.h>

using namespace std;
const int maxm = 1e5 + 10;
int n;
vector<pair<int, int>> son[maxm]; // first is to, second is index
int pre[maxm][17];
int dep[maxm];
int num[maxm];
int ans[maxm];

void my_assert(bool a, string ind) {
    if (!a) {
        cout << "assert failed" << ' ' << ind << endl;
        exit(0);
    }
}

void dfs1(int ind = 1, int p = 1, int d = 0) {/*{{{*/
    my_assert(d <= n, "dfs1");
    dep[ind] = d;
    pre[ind][0] = p;
    for (int i = 1; i < 17; i++) pre[ind][i] = pre[pre[ind][i - 1]][i - 1];
    for (auto s : son[ind]) {
        if (s.first == p) continue;
        dfs1(s.first, ind, d + 1);
    }
}/*}}}*/
int find(int a, int b) { // return the lca of a and b{{{
    if (dep[a] > dep[b]) swap(a, b);
    if (dep[a] < dep[b]) { // after that, the dep of a and b is equal
        int diff = dep[b] - dep[a];
        for (int i = 16; i >= 0; i--) if (diff & (1 << i)) b = pre[b][i];
    }
    my_assert(dep[a] == dep[b], "dep equal");
    for (int i = 16; i >= 0; i--) if (pre[a][i] != pre[b][i]) a = pre[a][i], b = pre[b][i];
    my_assert(pre[a][0] == pre[b][0], "pre equal");
    if (a != b) return pre[a][0];
    return a;
}/*}}}*/
void handler(int a, int b) {/*{{{*/
    num[a]++;
    num[b]++;
    num[find(a, b)] -= 2;
}/*}}}*/
int dfs2(int ind = 1, int p = 1) {
    my_assert(ind <= n && p <= n, "dfs2");
    int ret = num[ind];
    for (auto s : son[ind]) {
        if (s.first == p) continue;
        auto buffer = dfs2(s.first, ind);
        ans[s.second] = buffer;
        ret += buffer;
    }
    return ret;
}

int main() {
#ifdef DEBUG
    freopen("./191/C/in", "r", stdin);
#endif
    cin >> n;
    for (int i = 1, from, to; i < n; i++) {
        cin >> from >> to;
        son[from].push_back(make_pair(to, i));
        son[to].push_back(make_pair(from, i));
    }
    dfs1(); // init the pre list;
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        handler(a, b);
    }
    dfs2();
    for (int i = 1; i < n; i++) cout << ans[i] << ' ';
    return 0;
}

