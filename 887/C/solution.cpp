#include <cstdio>
#include <cmath>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 15;
int a[maxn];
int mp[maxn][maxn];
 
int main()
{
    int ans=0;
    for(int i=0; i<6; i++)
    {
        set<int>s;  //检测元素是否相同用set集合最便捷了，要记住
        for(int j=0; j<4; j++)
        {
            int x;
            scanf("%d",&x);
            s.insert(x);
        }
        if(s.size()==1) ans++;              //单个面颜色相同
        else if(s.size()==2)                //单个面两种颜色，需要记录
        {
            int pre=-1,pre1=-1;
            for(auto it: s) //auto是C++ 11里面的 相当于自动检测类型
            {
                if(pre==-1) pre=it;
                else pre1=it;
            }
            if(pre>pre1) swap(pre,pre1);  //排序用 便于记录环
            mp[pre][pre1]++;                //标记 记录环的个数用
        }
        else                         //单个面出现三种及以上颜色，显然不满足
        {
            puts("NO");
            return 0;
        }
    }
    if(ans==2)                  //两个面相同，四个面各两种颜色才满足条件
    {
        for(int i=1; i<=6; i++)
            for(int j=1; j<=6; j++)
            {
                if(mp[i][j]>=2)
                {
                    puts("NO");
                    return 0;
                }
            }
        puts("YES");
    }
    else puts("NO");
}
