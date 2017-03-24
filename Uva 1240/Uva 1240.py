dp = [[[ [0] for i in range(301) ] for j in range(3) ] for k in range(1<<12) ]
 
n = 0
kp1 = list()
kp2 = list()
kp2 = list()
 
 
def re(mask,last,s):
    if s<0:
        return -12345678
    if (1<<n)-1 == mask :
        return 0

    if dp[mask][last][s]!=-1:
        return dp[mask][last][s]

    dp[mask][last][s] =0

    for i in range(n):
        if (mask&(1<<i))==0:
            if last !=0:
                dp[mask][last][s]=max(dp[mask][last][s],1+re(mask|(1<<i),0,s-kp1[i]) )
            if last !=1:
                dp[mask][last][s]=max(dp[mask][last][s],1+re(mask|(1<<i),1,s-kp2[i]) )
            if last != 2:
                dp[mask][last][s]=max(dp[mask][last][s],1+re(mask|(1<<i),2,s-kp3[i]) )

    return dp[mask][last][s]
 
def main():
    t =int( input() )
    global n,kp1,kp2,kp3
 
    while t>0:
        n = int ( input() )
 
        kp1 = list( map(int,raw_input().split(' ') ) ) 
        kp2 = list( map(int,raw_input().split(' ') ) ) 
        kp3 = list( map(int,raw_input().split(' ') ) ) 
 
        for i in range(1<<n):
            for j in range(3):
                for k in range(300):
                    dp[i][j][k]=-1

        print (max(re(0,0,280),max(re(0,1,280),re(0,2,280) ) ) )         
 
        while len(kp1):
            kp1.pop()
            kp2.pop() 
            kp3.pop()        
 
        t-=1
 
 
main()