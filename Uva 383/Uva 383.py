

m =0
n =0
p =0
idx =0
maps = dict()

dp = [[[0] for i in range(32) ] for j in range(32)]

def conv (s):

    num =0

    for i in s:
        num=num*10+ord(i)-ord('0')

    return num

def main():

    global m,n,p,maps,idx

    t = int(input() )
    tcase=1

    print ("SHIPPING ROUTES OUTPUT\n")

    while t>0:
        
        m,n,p = map(int,input().split(' ') )
        idx =0  

        s = list(map(str,input().split(' ')) )

        for i in s:
            idx+=1
            maps[i]=idx 

        for i in range(m+3):
            for j in range(m+3):
                if(i==j):
                    dp[i][j]=0
                else:
                    dp[i][j]=123456

        for i in range(0,n):
            
            s = list(map(str,input().split(' ')) )

            
            dp[maps[s[0] ] ] [ maps[s[1] ]] = 1
            dp[maps[s[1] ] ] [ maps[s[0] ]] = 1

        for k in range(1,m+1):
            for i in range(1,m+1):
                for j in range(1,m+1):
                    try:
                      dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j] )
                    except:
                      print (str("**** ")+ str(i) + " " + str(j))


        print ('DATA SET  '+ str(tcase) + "\n" ) 


        while p:

            s = list(map(str,input().split(' ') ) )

            if dp[maps[s[1] ] ][maps[s[2] ] ]==123456:
                print ("NO SHIPMENT POSSIBLE")
            else:

                print ("$"+str(conv(s[0])*dp[maps[s[1] ] ][maps[s[2] ] ]*100) )

            p-=1
        
        print ("\n",end='')
        
        tcase+=1
        t-=1
    print ("END OF OUTPUT")

main()