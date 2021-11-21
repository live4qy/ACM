#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
struct Node{
    vector<int>pre;
    vector<int>ask;
    int mi;
    PI from(int x,int f){
        if(f)return {0,1};
        return {x<ask.size()?ask[x]:0,x+mi<0};
    }
    Node(){
        string s;cin>>s;
        int n=s.size();
        mi=0;
        for(int i=0,sum=0;i<n;i++){
            sum+=(s[i]=='('?1:-1);
            pre.push_back(sum);
            mi=min(mi,sum);
        }
        //pos存每个负数前缀和出现的位置
        vector<vector<int> >pos(-mi+1);
        for(int i=0;i<n;i++){
            if(pre[i]>0)continue;
            pos[-pre[i]].push_back(i);//负数下标转正数
        }
        //ask[x]表示前缀为x的合法串,追加当前串后答案的增加量.
        ask.resize(-mi+1);
        for(int i=0;i<-mi+1;i++){
            //合法的位置必须满足在errPos之前
            //因为errPos往后的所有串前缀不合法,不能产生贡献.
            //对于当前x=i,errPos是第一个出现-(x+1)的位置
            int errPos=1e9;
            if(i!=-mi)errPos=pos[i+1][0];
            ask[i]=lower_bound(pos[i].begin(),pos[i].end(),errPos)-pos[i].begin();
        }
    }
};
vector<Node>g;
int d[1<<22][2];
int b[1<<22];
int n;
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        g.push_back(Node());
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i>>j&1){
                b[i]+=g[j].pre.back();
            }
        }
    }
    //dp
    for(int i=0;i<(1<<n);i++)d[i][0]=d[i][1]=-1;
    d[0][0]=0;
    for(int i=0;i<(1<<n);i++){
        for(int f=0;f<2;f++){
            if(d[i][f]<0)continue;
            for(int j=0;j<n;j++){
                if(i>>j&1)continue;
                int nt=(i|(1<<j));
                PI chg=g[j].from(b[i],f);
                d[nt][chg.second]=max(d[nt][chg.second],d[i][f]+chg.first);
            }
        }
    }
    //
    int ans=max(d[(1<<n)-1][0],d[(1<<n)-1][1]);
    cout<<ans<<endl;
    /*
    前置知识:
    设左括号为1右括号为-1,
    那么满足条件的括号序列一定时刻前缀和>=0且最后和为0.

    参考的英文题解:

    n只有20,考虑状压

    令d[m][b][f]表示:
    1.用了m状态的串,
    2.当前前缀和为b,
    3.当前是否存在负数过前缀和(用于判断当前串是否合法).
    的最大合法括号前缀数.

    我们可以优化掉状态b,因为m固定,b也是固定的,预处理存一下就行了.
    那么只剩下d[m][f]了.
    状态数O(2^(n+1)).

    为了转移,我们需要想办法维护转移时f和答案的变化.
    发现不太好维护.

    可以预处理s[i].from[x][f]表示当前前缀和为x,符号为f,添加s[i]后的答案变化量.
    1.f的维护:
    如果之前f已经为1,那么之后f还是1.
    预处理每个s[i]的最小前缀,就能判断拼接之后是否合法了,不合法则f=1.
    2.答案的维护:
    如果之前f已经为1,那么答案不会变化.
    其实是维护新增了多少个合法前缀.假设当前前缀为b,
    那么答案新增其实就是看新增的串中有多少个-b,
    每个串预处理一个vector,存该串的所有前缀和,排序二分就能拿到-b的数量了.
    但是直接二分是不对的,因为一个串对于当前x,可能前面一部分是合法的,后面不合法.
    因此我们要找到对于这个x,出现不合法的位置errPos,只取errPos前面的-b.
    详见代码
    
    预处理完s[i].from[x][f]后,状压dp转移就是O(1)的了.
    直接dp就可以通过此题.
    */
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