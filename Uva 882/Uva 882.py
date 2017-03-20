
v = int(-1)
dp =[ [ [ [v] for i in range(102) ] for j in range(102) ] for k in range(12) ] 

def re(p,l,r):
    if l>r: return 0

    if p==0: return 12345678

    if dp[p][l][r]!=-1: 
        return dp[p][l][r]
  
    dp[p][l][r]=int(12345678)

    for i in range(l,r+1):
        dp[p][l][r] = min(dp[p][l][r], i+max(re(p,i+1,r),re(p-1,l,i-1) ) )        
 
    return dp[p][l][r]

for i in range (0,11):
    for j in range(0,101):
        for k in range(0,101):
            dp[i][j][k]=-1

def main():
    t = int(input())

    while t>0:
        
        a,b = map(int,input().split(' ') )
 

        t-=1

        print (re(a,1,b))

main()