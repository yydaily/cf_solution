#include<bits/stdc++.h>
using namespace std;
double x[30], y[30], r[30];
double dp[1<<22];
double cal(double x0,int right, int i) {
    double sita1=r[i]+atan((1.0*x0-1.0*x[i])/y[i]*1.0);
    double sita2=atan((right-1.0*x[i])/(1.0*y[i]));
    return 1.0*x[i]+1.0*y[i]*tan(min(sita1,sita2));
}
int main() {
	int n;
	double left, right;
	cin>>n>>left>>right;
	right-=left;
	for(int i = 0;i<n;i++) cin>>x[i]>>y[i]>>r[i], r[i] = r[i] / 45 * atan(1), x[i]-=left;
	for(int i = 1;i<(1<<n);i++) for(int j = 0;j<n;j++) 
		if(i&(1<<j)) dp[i] = max(dp[i], cal(dp[i^(1<<j)], right, j));
	printf("%.20f\n", dp[(1<<n)-1]);
}

