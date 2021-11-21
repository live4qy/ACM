#include<bits/stdc++.h>
#define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
char s[5][100];
int d[5][100];
int n;
void solve(){
    cin>>n;
    cin>>(s[1]+1);
    cin>>(s[2]+1);
    for(int i=0;i<5;i++){
        for(int j=0;j<=n;j++){
            d[i][j]=0;
        }
    }
    d[1][1]=1;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=2;i++){
            if(s[i][j]=='0'){
                d[i][j]|=d[i-1][j]|d[i+1][j];//上下
                d[i][j]|=d[i][j-1];//左
                d[i][j]|=d[i-1][j-1]|d[i+1][j-1];//左对角
            }else{
                d[i][j]=0;
            }
            // if(d[i][j]){
            //     cout<<i<<' '<<j<<endl;
            // }
        }
    }
    if(d[2][n]){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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