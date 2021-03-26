#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int x,y,a,b; cin>>x>>y>>a>>b;
		int xmax = max(x-a-1, a), ymax = max(y-b-1, b);
		cout<<max(xmax*y, ymax*x)<<"\n";
	}
}
