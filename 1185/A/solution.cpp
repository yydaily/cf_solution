#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[3], d;
int main() {
	scanf("%lld%lld%lld%lld", &a[0], &a[1], &a[2], &d);
	sort(a, a + 3);
	ll dd = a[2] - a[1];
	ll ans = 0;
	if (dd < d) ans += d - dd;
	dd = a[1] - a[0];
	if (dd < d) ans += d - dd;
	printf("%lld\n", ans);
}
