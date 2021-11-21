#include<bits/stdc++.h>
#define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
char s[maxm];
int n;char c;
void solve(){
    cin>>n>>c;
    cin>>(s+1);
    //选择一个x,i%x!=0的位置全部修改为c
    //1<=x<=n
    vector<int>ans;
    vector<int>temp;
    for(int i=1;i<=n;i++){
        if(s[i]!=c){
            temp.push_back(i);
        }
    }
    if(temp.size()==0){
        cout<<0<<endl;return ;
    }
    for(int i=n;i>=1;i--){//末尾有连续c的情况
        if(s[i]==c){
            cout<<1<<endl;
            cout<<i<<endl;
            return ;
        }else{
            break;
        }
    }
    //末尾没有连续c的情况
    //即连续!=c

    //判断是否可以一步到位
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=i;j<=n;j+=i){
            if(s[j]!=c){
                cnt++;
            }        
        }
        if(!cnt){
            cout<<1<<endl;
            cout<<i<<endl;
            return ;
        }
    }
    //否则至少需要两步
    cout<<2<<endl;
    cout<<n-1<<' '<<n<<endl;
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