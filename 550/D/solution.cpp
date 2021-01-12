#include<bits/stdc++.h>

using namespace std;

int num[1000];

void solve(int a) {
    auto point = (a + 2) << 1;
    cout << point << ' ' << (point * a / 2) << endl;
    cout << 1 << ' ' << a + 3 << endl;
    for (int i = 1; i <= a + 2; i++) {
        num[i] = a;
    }
    num[1]--;
    for (int i = 1; i <= a + 2; i++) {
        auto lower = a + 2, upper = i + 1, add = -1;
        if (i & 1) lower = i + 1, upper = a + 2, add = 1;
        for (int j = lower; j != upper + add; j += add) {
            if (num[i] && num[j]) {
                cout << i << ' ' << j << endl;
                cout << i + a + 2 << ' ' << j + a + 2 << endl;
                num[i]--;
                num[j]--;
            }
        }
    }
}

int main() {
    int k;
    cin >> k;
    if (k & 1) {
        puts("YES");
        if(k==1) {
            puts("2 1\n1 2");
            return 0;
        }
        solve(k);
    } else {
        puts("NO");
    }
    return 0;
}
