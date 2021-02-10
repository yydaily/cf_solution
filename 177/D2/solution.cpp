#include <iostream>
#include <vector>
#include <bitset>
#define FORE(i, v) for(typeof((v).begin()) i = (v).begin(); i!=(v).end(); i++)
using namespace std;
vector<int> f(0);
int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> a(n);
    vector<int> b(m);
    f = vector<int> (m + 1, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    f[0] = 0;
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        f[i+1] = f[i] + b[i];
    }
    for(int i = 0;i<n;i++)
        cout<<(a[i] + f[min(i+1, m)] - f[max(i-n+m, 0)]) % c<<" ";
    cout<<endl;
    return 0;
}
