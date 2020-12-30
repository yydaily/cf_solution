#include<bits/stdc++.h>

using namespace std;
int n, m;
const int maxm = 2e5 + 10;
char origin[maxm];
int tree[maxm << 2];
set<int> s[100];

struct ans {
    char a;
    int ind;
};

bool cmp(ans a, ans b) {
    return a.ind < b.ind;
}

vector<ans> answer;

int get(char a) {
    if (islower(a)) return a - 'a';
    if (isupper(a)) return a - 'A' + 30;
    return a - '0' + 60;
}

char get(int a) {
    if (a >= 60) return a - 60 + '0';
    if (a >= 30) return a - 30 + 'A';
    return a + 'a';
}

void add(int x, int addition = 1, int ind = 1, int nowl = 1, int nowr = n) {/*{{{*/
    if (nowl == nowr) {
        tree[ind] += addition;
        return;
    }
    int mid = (nowl + nowr) >> 1;
    if (x <= mid) {
        add(x, addition, ind << 1, nowl, mid);
    } else {
        add(x, addition, ind << 1 | 1, mid + 1, nowr);
    }
    tree[ind] = tree[ind << 1] + tree[ind << 1 | 1];
}/*}}}*/

int get_real_ind(int cnt, int ind = 1, int nowl = 1, int nowr = n) {
    if (nowl == nowr) return nowl;
    int mid = (nowl + nowr) >> 1;
    if (tree[ind << 1] >= cnt) return get_real_ind(cnt, ind << 1, nowl, mid);
    return get_real_ind(cnt - tree[ind << 1], ind << 1 | 1, mid + 1, nowr);
}

void handler(int ind1, int ind2, int que) {
    ind1 = get_real_ind(ind1);
    ind2 = get_real_ind(ind2);

    while (true) {
        auto it = s[que].lower_bound(ind1);
        if (it == s[que].end() || *it > ind2) break;
        add(*it, -1);
        s[que].erase(it);
    }
}

int main() {/*{{{*/
#ifdef DEBUG
    freopen("./899/F/in", "r", stdin);
#endif
    cin >> n >> m >> (origin + 1);
    for (int i = 1; i <= n; i++) {
        add(i);
        s[get(origin[i])].insert(i);
    }
    for (int i = 0; i < m; i++) {
        int ind1, ind2;
        char que;
        cin >> ind1 >> ind2 >> que;
        handler(ind1, ind2, get(que));
    }
    for (int i = 0; i < 100; i++) {
        auto x = get(i);
        for (auto it = s[i].begin(); it != s[i].end(); it++) {
            answer.push_back(ans{x, *it});
        }
    }
    sort(answer.begin(), answer.end(), cmp);
    for(auto a : answer) {
        cout<<a.a;
    }
    cout<<endl;
    return 0;
}/*}}}*/

