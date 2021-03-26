#include <bits/stdc++.h>
using namespace std;
 
int main(){
	boost;
	int a,b,c;
	cin>>a>>b>>c;
	int x,y,z;
	cin>>x>>y>>z;
	if((x-a)<0) cout<<"No";
	else if((y-(b+ a-x))<0) cout<<"No";
	else if((z-(b-y+ a-x+c))<0) cout<<"No"; 
	else cout<<"Yes";
}
