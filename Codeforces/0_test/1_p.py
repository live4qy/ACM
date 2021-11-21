maxm=5005

d=[0 for i in range(maxm)]

def init():
    d[0]=1
    for j in range(1,maxm): #从小到大枚举数字,等价于从小到大取
        for i in range(j,maxm): #完全背包
            d[i]+=d[i-j]


init()

while True:
    try:
        n=int(input())
        print(d[n])
    except:
        break