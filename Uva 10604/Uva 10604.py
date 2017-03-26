

kp = [ [ [ [0] for i in range(2)] for j in range(8) ] for k in range(8) ]
dp = [ [ [0,0] for i in range(8)] for j in range(8) ]

def re(l,r):
    if l==r:
        return [ kp[l][r][0],kp[l][r][1] ]
    elif l>r:
        return [0,0]

    if dp[l][r][0] !=[-1]:
        return dp[l][r]

    dp[l][r] =[0,0]

    for i in range(l,r+1):
        r1 =re(l,i)
        r2 =re(i+1,r)

        dp[l]


def main():
    pass


main()