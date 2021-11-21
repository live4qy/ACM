#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
// #define int long long
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
int n;
/*
题目要求:
任选三个点连接成三角形,
满足这个三角形内有奇数个整数点,
且三角形的面积是整数.
求方案数

数据范围:
n<=6000,
0<=(x,y)<=1e7,
每个点的坐标都是偶数.
*/
/*
皮克定理:
设面积为S,I为多边形内整数点的数量,B为多边形边上整数点的数量,
那么有:
S=I+B/2-1

由于给定点的坐标都是偶数,
可推出S也一定是偶数.

题目要求I是奇数,
我们只需要考虑奇偶性,
那么S,1,I都是已知的了.

我们看看B需要满足什么条件,
先将式子变为:
S-B/2+1=I

S是偶数,1是奇数,I是奇数,
那么只需要满足B/2是偶数.
即B必须是4的倍数.

问题变为选出三个点连成三角形,满足边上点的总个数是4的倍数.

(x1,x2),(y1,y1)的连线,边上整数点的个数为:gcd(x1-x2,y1-y2)+1.
三条边的总个数为(gcd1+1)+(gcd2+1)+(gcd3+1)-3=gcd1+gcd2+gcd3.
减3是因为三个点被重复计算了一次.

由于坐标一定是偶数,因此gcd一定是偶数,
为了使gcd的和%4=0,有两种情况:
1.三个gcd都为0
2.一个gcd为0,两个gcd为2.

1.对于情况1,需要满足三对下标差是4的倍数.
下标差是4的倍数,那么两两之间x%4和y%4一定相等.
2.对于情况2,需要满足一对下标查是4的倍数,另外两对下标差是2的倍数但不是4的倍数.
下标差是4的倍数,那么两两之间x%4和y%4一定相等.
下标差是2的倍数,那么一个点x%4=1,一个点x%4=3,或者x%4=0和x%4=2
'因为x和y是偶数,所以x%4和y%4一定是0或者2',
所以下标差为2一定是x%4=0和x%4=2.
y也需要满足以上条件,我就不写了.

发现只需要考虑坐标%4的情况即可.
先对坐标%4,那么只有cnt[4][4]种点需要计算了,
暴力计算即可.

*/
void solve(){
    cin>>n;
    int cnt[4][4]={0};
    for(int i=1;i<=n;i++){  //题目保证所有坐标是偶数
        int x,y;cin>>x>>y;
        cnt[x%4][y%4]++;
        //因为x和y是偶数,所以x%4和y%4一定是0或者2
    }
    // for(int i=0;i<4;i+=2){
    //     for(int j=0;j<4;j+=2){
    //         cout<<i<<' '<<j<<' '<<cnt[i][j]<<endl;
    //     }
    // }
    ll ans=0;
    //因为x和y是偶数,所以x%4和y%4一定是0或者2
    for(int i=0;i<4;i+=2){
        for(int j=0;j<4;j+=2){
            int q=cnt[i][j];
            //情况1:两两%4相等
            ans+=1ll*q*(q-1)*(q-2)/6;
            //情况2:一对gcd=0,两对gcd=2
            //gcd=0从cnt[i][j]取出两个
            //gcd=2则需要再找一种点,枚举找
            for(int x=0;x<4;x+=2){
                for(int y=0;y<4;y+=2){
                    int g=gcd(abs(x-i),abs(y-j));
                    if(g==2){//需要满足gcd=2
                        int e=cnt[x][y];
                        ans+=1ll*q*(q-1)/2*e;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
void Main(){
    #ifdef MULTI_CASE
    int T;cin>>T;while(T--)
    #endif
    solve();
}
void Init(){
    #ifdef SYNC_OFF
    ios::sync_with_stdio(0);cin.tie(0);
    #endif
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
}
signed main(){
    Init();
    Main();
    return 0;
}