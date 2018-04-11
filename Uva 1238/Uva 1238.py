
global kp1,kp2
kp1 = list()

kp2 = list()

dp = [ [ [ [ [False] for l in range(2) ] for k  in range(32) ] for i in range(100*32)  ] for j in range(32)]
 
keep = set()

def re(p,v,cnt,s): 
    if p == len(kp1): 
        global keep
        #print ( -v if s==1 else v )
        keep.add( -v if s==1 else v ) 

        return 

    if dp[p][v][cnt][s]==True:
        return

    dp[p][v][cnt][s] = True

    v = -v if s==1 else v

    if cnt==0:
        if kp1[p]==1:
            re(p+1,abs(v+kp2[p]),cnt,1 if (v+kp2[p])<0 else 0 )
        else:
            re(p+1,abs(v-kp2[p]),cnt+1,1 if (v-kp2[p])<0 else 0 )         
            re(p+1,abs(v-kp2[p]),cnt,1 if (v-kp2[p])<0 else 0 )         
    else:
        if kp1[p]==1:
            z = (v+ (-1 if (cnt%2!=0) else 1 ) * kp2[p] )
            re(p+1,abs(z) ,cnt,1 if (z)<0 else 0 )
            re(p+1,abs(z) ,cnt-1,1 if (z)<0 else 0 )            
        else:
            z = (v+ (1 if (cnt%2!=0) else -1 ) * kp2[p] )
            re(p+1,abs(z) ,cnt,1 if (z)<0 else 0 )
            re(p+1,abs(z) ,cnt-1,1 if (z)<0 else 0 )            
            #cnt+=1
#            z = (v+ (1 if (cnt%2!=0) else -1 ) * kp2[p] )
            re(p+1,abs(z) ,cnt+1,1 if (z)<0 else 0 )            


def conv(s):
    v= int(0)
    for i in s:
        v=v*10 + ord(i)-48     
    return v

def main():
    c =0
    while True:
        try:
            s = raw_input().split(' ') 
        except:
            break
 

        kp1.append(1)
        kp2.append(conv(s[0]) )

        sum=kp2[0]
        idx =1

        for i in range(1,len(s),2):

            if s[i]=='+':
                kp1.append(1)
            else:
                kp1.append(-1)
            kp2.append(conv(s[i+1]) )

            sum += kp2[-1]
            
        sum = 2 * sum  

        for i in range(0,len(kp1)+3):
            for j in range(sum+3):
                for k in range(len(kp1)+3):
                    dp[i][j][k][0]=True
                    dp[i][j][k][1]=True

        res = 0 

        re(0,0,0,0)

        print (len(keep)) 
        keep.clear()


        while len(kp1)>0:
            kp1.pop()
            kp2.pop()


        c+=1
main()