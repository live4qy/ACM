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
char s[maxm];
PI pre[44][44][44][44];
int d[44][44][44][44];
int n,A,B;
void solve(){
    cin>>n>>A>>B;
    cin>>(s+1);
    for(int i=1;i<=n;i++)s[i]-='0';
    for(int i=0;i<=n;i++){
        for(int j=0;j<=A;j++){
            for(int k=0;k<=B;k++){
                for(int t=0;t<=n;t++){
                    d[i][j][k][t]=0;
                }
            }
        }
    }
    d[0][0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<A;j++){
            for(int k=0;k<B;k++){
                for(int t=0;t<=n;t++){
                    if(!d[i][j][k][t])continue;
                    //A
                    d[i+1][(j*10+s[i+1])%A][k][t+1]=1;
                    pre[i+1][(j*10+s[i+1])%A][k][t+1]={0,j};
                    //B
                    d[i+1][j][(k*10+s[i+1])%B][t]=1;
                    pre[i+1][j][(k*10+s[i+1])%B][t]={1,k};
                }
            }
        }
    }
    int ans=1e9;
    int tt=-1;
    for(int t=1;t<=n-1;t++){
        if(d[n][0][0][t]){
            // cout<<t<<' ';
            int dif=abs(t-(n-t));
            if(dif<ans){
                ans=dif;
                tt=t;
            }
        }
    }
    // cout<<endl;
    if(ans==1e9){
        cout<<-1<<endl;return ;
    }
    stack<char>stk;
    int j=0,k=0,t=tt;
    for(int i=n;i>=1;i--){
        if(pre[i][j][k][t].first==0){
            stk.push('R');
            j=pre[i][j][k][t].second;
            t--;
        }else{
            stk.push('B');
            k=pre[i][j][k][t].second;
        }
    }
    while(stk.size()){
        cout<<stk.top();stk.pop();
    }
    cout<<endl;
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