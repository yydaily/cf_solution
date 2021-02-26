#include<bits/stdc++.h>
using namespace std;
int n,m,k;int ans=0,a[200100];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	int cur=0,cnt=1;
	for(int i=n;i;i--)
	{
		if(cur+a[i]<=k) cur+=a[i],ans++;
		else
		{
			cur=a[i];cnt++;
			if(cnt>m) break;
			ans++;
		}
	}
	cout<<ans;
}

