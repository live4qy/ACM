def cal(x:int):
    return x*(x+1)//2

a,b,c,n=map(int,input().split(' '))
# print(a,b,c,n)

mod=2**64

ans=0
if n%2==0: #[2,n/2]*2+(n-2)
    ans=(2*cal(n//2)-2+(n-2))*n
    pass
else: #[1,n/2]*2
    ans=(2*cal(n//2))*n
    pass

if a==b and b==c:
    ans//=6
elif a==b or b==c or a==c:
    ans//=2

print(ans%mod)