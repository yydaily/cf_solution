#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
const int MAXN=1001, INF=0x0FFFFFFF;
 
int n;
int a[105];
 
int main() {
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int maxx=0,minn=n-1,ans;
	for(int i=0;i<n;i++)
		if( a[i] > a[maxx] ) maxx=i;
	for(int i=n-1;i>=0;i--)
		if( a[i] < a[minn] ) minn=i;
	// 10 10 58 31 63 40 76
	ans = maxx+(n-1-minn);
	if(maxx>minn) ans--;
		cout << ans << '\n';
	return 0;
}
