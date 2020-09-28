#include<bits/stdc++.h>

using namespace std;
int n, m;
string buf;
const int maxm = 502;
int mat[maxm][maxm];
int cost[maxm][30][30];
int dp[maxm][30][30];
pair<int, int> pre[maxm][30][30];

void cal(int row, int a, int b) {
    cost[row][a][b] = 0;
    if (a == b) {
        cost[row][a][b] = 0x3f3f3f3f;
        return;
    }
    for (int i = 0; i < m; i++) {
        if (i & 1) {
            cost[row][a][b] += mat[row][i] != b;
        } else {
            cost[row][a][b] += mat[row][i] != a;
        }
    }
//    cout<<"cost["<<row<<"]["<<a<<"]["<<b<<"]="<<cost[row][a][b]<<endl;
}

void process() {
    memset(dp, 0x5f, sizeof(dp));
    for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) dp[0][i][j] = cost[0][i][j];
    for (int i = 1; i < n; i++) {
        for (int a = 0; a < 26; a++)
            for (int c = 0; c < 26; c++) {
                if (a == c) continue;
                for (int b = 0; b < 26; b++)
                    for (int d = 0; d < 26; d++) {
                        if (b == d) continue;
                        if (dp[i][a][b] > dp[i - 1][c][d] + cost[i][a][b]) {
                            dp[i][a][b] = dp[i - 1][c][d] + cost[i][a][b];
                            pre[i][a][b] = make_pair(c, d);
                        }
                    }
            }
    }
//    for(int a = 0;a<26;a++) for(int b = 0;b<26;b++) {
//        cout<<"dp["<<a<<"]["<<b<<"]="<<dp[n-1][a][b]<<endl;
//    }
}

void pack() {
    int ans = 0x3f3f3f3f;
    int a, b;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++) {
            if (ans > dp[n - 1][i][j]) {
                ans = dp[n - 1][i][j];
                a = i;
                b = j;
            }
        }
    cout << ans << endl;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (j & 1) mat[i][j] = b;
            else mat[i][j] = a;
        }
        int aa = pre[i][a][b].first;
        int bb = pre[i][a][b].second;
        a = aa, b = bb;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << char(mat[i][j] + 'a');
        cout << endl;
    }
}

int main() {
#ifdef debug_mod
    cout << "debug mod" << endl;
    freopen("./in", "r", stdin);
#endif
    cin>>n>>m;
    for(int i = 0;i<n;i++) {
        cin>>buf;
        for(int j = 0;j<m;j++) mat[i][j] = buf[j] - 'a';
    }
    for(int i = 0;i<n;i++) for(int a = 0;a<26;a++) for(int b = 0;b<26;b++) cal(i, a, b);
    process();
    pack();
    return 0;
}


