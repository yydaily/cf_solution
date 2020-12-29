#include<bits/stdc++.h>

using namespace std;
int n, m, a, b;
vector<int> to[123456];


vector<int> sub(vector<int> a, vector<int> b) {
    int ind = 0;
    vector<int> ret;
    for (auto i : a) {
        while (ind < b.size() && b[ind] < i) ind++;
        if (b.size() <= ind) {
            ret.push_back(i);
            continue;
        }
        assert(b[ind] >= i);
        if (b[ind] == i) continue;
        ret.push_back(i);
    }
    return ret;
}

// return the same value in two vector
vector<int> intersection(vector<int> a, vector<int> b) {
    int ind = 0;
    vector<int> ret;
    for (auto i : a) {
        while (ind < b.size() && b[ind] < i) ind++;
        if (b.size() <= ind) break;
        assert(b[ind] >= i);
        if (b[ind] == i) ind++, ret.push_back(i);
    }
    return ret;
}

vector<int> merge(vector<int> a, vector<int> b) {
    for (auto i : b) a.push_back(i);
    return a;
}

void show(vector<int> buffer) {
    for (auto i : buffer) cout << i << ' ';
    cout << endl;
}

void solve(int x, int y) {
    cout << x << ' ' << y << endl;
    auto same_set = intersection(to[x], to[y]);
//    show(same_set);
    vector<int> ansl, ansr;
    ansl = merge(ansl, sub(to[x], same_set));
//    show(ansl);
    ansr = merge(ansr, sub(to[y], same_set));
//    show(ansr);
    for (auto i : same_set) {
        if (ansl.size() < a) {
            ansl.push_back(i);
            continue;
        }
        if (ansr.size() < b) {
            ansr.push_back(i);
            continue;
        }
    }
    assert(ansl.size() >= a);
    assert(ansr.size() >= b);
    for (auto i : ansl) {
        if (i == y || a <= 1) continue;
        a--;
        cout << i << ' ';
    }
    cout << endl;
    for (auto i : ansr) {
        if (i == x || b <= 1) continue;
        b--;
        cout << i << ' ';
    }
    cout << endl;
}

bool check(int x, int y) {
    if (to[x].size() < a || to[y].size() < b) return false;
    auto same_set = intersection(to[x], to[y]);
    auto l = sub(to[x], same_set).size();
    auto r = sub(to[y], same_set).size();
    if (l >= a) return to[y].size() >= b;
    if (l + same_set.size() < a || r + same_set.size() < b) return false;
    else return to[x].size() + to[y].size() - same_set.size() >= a + b;
}

int main() {
#ifdef DEBUG
    freopen("./244/D/in", "r", stdin);
#endif
    cin >> n >> m >> a >> b;
    a++, b++;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) sort(to[i].begin(), to[i].end());
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < to[i].size(); j++) {
            if (check(i, to[i][j])) {
                puts("YES");
                solve(i, to[i][j]);
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}

