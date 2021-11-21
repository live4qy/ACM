#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
char s[maxm];
int n;
void solve(){
    cin>>(s+1);
    n=strlen(s+1);//n<=1e5
    for(int i=1;i<=n;i++)s[i]-='0';
    //无解情况
    int eve=0;
    for(int i=1;i<=n;i++)if(s[i]%2==0)eve=1;
    if(!eve){
        cout<<-1<<endl;return ;
    }
    //有解情况
    //交换之后变大
    for(int i=1;i<=n;i++){
        if(s[i]%2==0&&s[n]>s[i]){
            swap(s[i],s[n]);
            for(int j=1;j<=n;j++){
                cout<<(int)s[j];
            }
            cout<<endl;return ;
        }
    }
    //交换之后变小
    for(int i=n;i>=1;i--){
        if(s[i]%2==0){
            swap(s[i],s[n]);
            for(int j=1;j<=n;j++){
                cout<<(int)s[j];
            }
            cout<<endl;return ;
        }
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