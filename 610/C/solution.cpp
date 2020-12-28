#include<bits/stdc++.h>

using namespace std;

int mul(vector<int> a, vector<int> b) {
    int ret = 0;
    for (int i = 0; i < a.size(); i++) {
        int x = a[i] == 1 ? 1 : -1;
        int y = b[i] == 1 ? 1 : -1;
        ret += x * y;
    }
    if (ret != 0) {
        cout << endl;
        for (auto x : a) cout << (x == 1 ? 1 : -1) << ' ';
        cout << endl;
        for (auto x : b) cout << (x == 1 ? 1 : -1) << ' ';
        cout << endl;
    }
    return ret;
}

void print(vector<vector<int> > ans) {
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) cout << (ans[i][j] == 1 ? '+' : (ans[i][j] == 0 ? '*' : '-'));
        cout << endl;
    }
    for (int i = 0; i < ans.size(); i++) for (int j = i + 1; j < ans.size(); j++) mul(ans[i], ans[j]);
}

void show(vector<int> ans) {
    for (auto i : ans) cout << (i == 1 ? '+' : (i == 0 ? '*' : '-'));
    cout << endl;
}

vector<vector<int> > handler(vector<vector<int> > buffer) {
    vector<vector<int>> ret;
	for(auto i : buffer) {
		vector<int> b;
		for(auto j : i) b.push_back(j);
		for(auto j : i) b.push_back(j);
		ret.push_back(b);
		for(int j = 0;j<i.size();j++) b[j+i.size()] = 1-b[j+i.size()];
		ret.push_back(b);
	}
	return ret;
}

void solve(int a) {
    vector<vector<int> > ans;
    ans.push_back(vector<int>{1, 1});
    ans.push_back(vector<int>{1, 0});
    for (int i = 2; i <= a; i++) ans = handler(ans);
    print(ans);
}

int main() {
    int a;
#ifdef DEBUG
    a = 3;
#endif
#ifndef DEBUG
    cin>>a;
#endif
    if (a == 0) puts("+");
    else solve(a--);
    return 0;
}

