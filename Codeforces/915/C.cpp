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
char s[maxm];
char t[maxm];
int n,m;
void solve(){
    cin>>(s+1)>>(t+1);
    n=strlen(s+1);
    m=strlen(t+1);
    if(n<m){
        sort(s+1,s+1+n);
        reverse(s+1,s+1+n);
        cout<<(s+1)<<endl;
    }else if(n==m){
        for(int i=1;i<=n;i++){
            s[i]-='0';
            t[i]-='0';
        }
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            mp[s[i]]++;
        }
        int ans=0;
        map<int,int>need;
        int pre=0;
        for(int i=1;i<=n;i++){//枚举s[i-1]==t[i-1]的最大位置
            //找<t[i]的最大值
            int ma=-1;
            for(int j=0;j<t[i];j++){
                if(mp[j]>0){
                    ma=j;
                }
            }
            if(!(i==1&&ma==0)&&ma!=-1){
                int res=pre;
                mp[ma]--;
                res=res*10+ma;
                vector<int>temp;
                for(int j=0;j<10;j++){
                    for(int x=0;x<mp[j];x++){
                        temp.push_back(j);
                    }
                }
                sort(temp.begin(),temp.end());
                reverse(temp.begin(),temp.end());
                for(auto i:temp){
                    res=res*10+i;
                }
                ans=max(ans,res);
                mp[ma]++;
            }
            mp[t[i]]--;
            if(mp[t[i]]<0)break;
            pre=pre*10+t[i];
            if(i==n){
                ans=max(ans,pre);
            }
        }
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