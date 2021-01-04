#include<bits/stdc++.h>

using namespace std;
const int maxm = 1e6 + 10;
int n, m, k, num[2];

vector<int> ans; // answer

int qpow(int a) {
    int ret = 1;
    int mod = 1e9 + 7;
    while (a--) ret = (ret << 1) % mod;
    return ret;
}

int pre[maxm];

int p(int a) {
    if(pre[a] != a) {
        int aa = p(pre[a]);
        pre[a] = aa;
    }
    return pre[a];
}

int main() {
#ifdef DEBUG
    freopen("./1466/F/in", "r", stdin);
#endif
    cin >> n >> m;
    for(int i = 1;i<=m;i++) pre[i] = i;
    for (int i = 1; i <= n; i++) {/*{{{*/
        cin >> k;
        for (int i = 0; i < k; i++) cin >> num[i];
        int from = num[0], to = num[1];
        if(k==1) to = 0;
        auto p_from = p(from), p_to = p(to);
        if(p_from != p_to) {
            ans.push_back(i);
            pre[p_from] = p_to;
        }
    }/*}}}*/
    cout << qpow(ans.size()) << ' ' << ans.size() << endl;
    for (auto i : ans) cout << i << ' ';
    cout << endl;
    return 0;
}
 
