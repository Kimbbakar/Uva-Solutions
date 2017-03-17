import math

def isPrime2(n):
    if n==2 or n==3: return True
    if n%2==0 or n<2: return False
    l = int(n**0.5)
    for i in range(3,l+1,2):   # only odd numbers
        if n%i==0:
            return False    

    return True

mark = [ [0] for i in range(0,10003) ]

for i in range(10002):
    mark[i]=0

for i in range(10001):

    if((i*i+i+41)&1):
        mark[i] = isPrime2(i*i+i+41);
    

    if i!=0:
        mark[i]+=mark[i-1]


while True:
    try:
        a, b = map(int, raw_input().split())
    except  :
        break #end of file reached 

    res = float(mark[b])

    if a:
        res-=mark[a-1];
 
    res/=(float) (b-a+1) 

    print '%.2f' % (res*100)  
