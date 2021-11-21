#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
map<int,int>col;
map<int,int>idx;int num;
map<int,bool>mark;//标记子树中至少有一个颜色的点
int lim[10][10];
int d[10][66];
int d2[2222*66][6];
int n,k;
map<char,int>c_mp={
    {'w',0},
    {'y',1},
    {'g',2},
    {'b',3},
    {'r',4},
    {'o',5},
};
/*
0是白 白黄
1是黄 白黄
2是绿 绿蓝
3是蓝 绿蓝
4是红 红橙
5是橙 红橙
*/
void init(){
    //初始化lim[][]
    lim[0][0]=lim[0][1]=1;
    lim[1][0]=lim[1][1]=1;
    lim[2][2]=lim[2][3]=1;
    lim[3][2]=lim[3][3]=1;
    lim[4][4]=lim[4][5]=1;
    lim[5][4]=lim[5][5]=1;
}
int dp_dfs(int c,int k){
    if(k==1)return 1;
    if(d[c][k]!=-1)return d[c][k];
    d[c][k]=0;
    for(int i=0;i<6;i++){//左边的颜色
        if(lim[c][i])continue;
        for(int j=0;j<6;j++){//右边的颜色
            if(lim[c][j])continue;
            d[c][k]=(d[c][k]+dp_dfs(i,k-1)*dp_dfs(j,k-1)%mod)%mod;
        }
    }
    return d[c][k];
}
int dfs(int c,int k,int id){
    if(col.count(id)&&col[id]!=c)return 0;//判断合法性
    if(k==1)return 1;//最后一层
    //如果子树中所有点都没有颜色,那么直接返回预处理的结果
    if(!mark.count(id))return d[c][k];
    //如果至少有一个子节点有颜色,那么记忆化搜索
    if(!idx.count(id))idx[id]=++num;
    int x=idx[id];//获取映射后的下标
    if(d2[x][c]!=-1)return d2[x][c];
    d2[x][c]=0;
    int l=id*2,r=id*2+1;
    for(int i=0;i<6;i++){//左边的颜色
        if(lim[c][i])continue;
        for(int j=0;j<6;j++){//右边的颜色
            if(lim[c][j])continue;
            d2[x][c]=(d2[x][c]+dfs(i,k-1,l)*dfs(j,k-1,r)%mod)%mod;
        }
    }
    return d2[x][c];
}
void solve(){
    init();
    cin>>k>>n;
    //初始化d[][]
    memset(d,-1,sizeof d);
    memset(d2,-1,sizeof d2);
    for(int i=0;i<6;i++){
        dp_dfs(i,k);
    }
    //
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        char s[10];cin>>s;
        col[x]=c_mp[s[0]];//点x的颜色
        while(x){//O(log)标记所有祖先节点
            mark[x]=1;
            x/=2;
        }
    }
    int ans=0;
    for(int i=0;i<6;i++){
        ans=(ans+dfs(i,k,1))%mod;
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