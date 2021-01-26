#include<bits/stdc++.h>
using namespace std;
int n, m;
long long handler() {
	int base_t, max_t, per_cost_people, per_cost_car;
	cin>>base_t>>max_t>>per_cost_people>>per_cost_car;
	int max_people_in_car = max_t - base_t;
	if(max_people_in_car <= 0) {
		return 1ll * per_cost_people * m + per_cost_car;
	}
	int car_cnt = m / max_people_in_car + (m%max_people_in_car != 0);
	return min(1ll * car_cnt * per_cost_car,
			1ll * per_cost_people * m + per_cost_car);
}
int main() {
	cin>>n>>m;
	long long ans = 0;
	while(n--) {
		ans += handler();
	}
	cout<<ans<<endl;
	return 0;
}

