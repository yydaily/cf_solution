#include <iostream>
#include <cstring>
 
using namespace std;
char mp[1005][1005];
 
int main() {
	int n;
	int i,j;
	int ans;
	cin>>n;
	ans=0;
	for (i=0;i<n;i++) for (j=0;j<n;j++) 
		if ((i+j)%2==0) {
			ans++;
			mp[i][j]='C';
		}
		else mp[i][j]='.';
	cout<<ans<<endl;
	for (i=0;i<n;i++) cout<<mp[i]<<endl;
	return 0;
}
