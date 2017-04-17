from queue import Queue 


lst = list()
mark = list()

for i in range(100005):
    lst.append(list())
    mark.append(0)

def bfs(a,b):
    q = Queue()

    q.put(a);
    mark[a] = 0

    while q.empty()==False:
        nw = q.get()
        if(nw==b):
            return mark[nw]
 

        for i in lst[nw]:
            
            if mark[i]==-1: 
                mark[i] = 1 + mark[nw]
                q.put(i)


def main():
    global lst

    t = int(input() )

    while t>0:
        tmp = input()

        n = int(input())

        for i in range(n):
            tmp = list(map(int,input().split(' ') ))
            lst[tmp[0] ] = list()
            mark[tmp[0] ] = -1

            for j in range(2,len(tmp)):
                lst[tmp[0] ].append(tmp[j])
              #  print tmp[0],tmp[j]


        a,b = map(int,input().split(' ') )

        print (a,b,bfs(a,b)-1)


        t-=1

        if t>0:
            print ("")

main()