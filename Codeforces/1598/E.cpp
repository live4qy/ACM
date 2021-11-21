#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
#define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
int d[1111][1111][2];//0表示作为右上角,1表示作为左下角
int a[1111][1111];
vector<PI>dir[4]{
    vector<PI>{{0,-1},{-1,0}},//左,上
    vector<PI>{{1,0},{0,1}},//下,右
    vector<PI>{{-1,0},{0,-1}},//上,左
    vector<PI>{{0,1},{1,0}},//右,下
};
int n,m,q;
void solve(){
    cin>>n>>m>>q;
    //0表示作为右上角,1表示作为左下角
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            d[i][j][0]=d[i][j][1]=1;
            d[i][j][0]+=d[i][j-1][1];
            d[i][j][1]+=d[i-1][j][0];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans+=d[i][j][0];
            ans+=d[i][j][1];
            ans--;//孤立点重复计算了一次
        }
    }
    //
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        int cnt[4]={0};
        for(int k=0;k<4;k++){
            int q=x,e=y;
            int p=0;
            cnt[k]=1;
            while(1){
                q+=dir[k][p].first;
                e+=dir[k][p].second;
                if(q<1||q>n||e<1||e>m||a[q][e])break;
                cnt[k]++;
                p^=1;
            }
        }
        /*
            vector<PI>{{0,-1},{-1,0}},//左,上
            vector<PI>{{1,0},{0,1}},//下,右
            vector<PI>{{-1,0},{0,-1}},//上,左
            vector<PI>{{0,1},{1,0}},//右,下
        */
        int res=cnt[0]*cnt[1]+cnt[2]*cnt[3]-1;
        ans+=res*(a[x][y]?1:-1);
        a[x][y]^=1;
        cout<<ans<<endl;
    }
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