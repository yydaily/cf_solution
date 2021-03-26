#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		printf("%d ",n);
		for(int i=1;i<n;i++)printf("%d ",i);printf("\n");
	}
	return 0;
}
