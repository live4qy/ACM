from sys import stdin

maxm=5005
d=[[-1 for i in range(maxm)] for j in range(maxm)]

def dfs(n:int,k:int):
    if n<0:return 0
    if n==0:return 1
    if k==0:return 0
    if d[n][k]!=-1:return d[n][k]
    d[n][k]=dfs(n,k-1)+dfs(n-k,k)
    return d[n][k]
    '''
    if(n<0)return 0;
    if(n==0)return 1;
    if(k==0)return 0;
    if(d[n][k]!=-1)return d[n][k];
    return d[n][k]=dfs(n,k-1)+dfs(n-k,k);
    '''



def solve(n:int):
    ans=dfs(n,n)
    print(ans)
    pass

def init():
    pass


init()
for line in stdin:
    line=line.strip()
    if line.isnumeric():
        n=int(line)
        solve(n)

# while True:
#     try:
#         solve()
#     except:
#         break
