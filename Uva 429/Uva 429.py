import queue

maps = dict()
mark = 1
v = [ 0 for i in range(202) ] 
 

def bfs(s,d):

    for i in range(mark+1):
        v[i] = 0

    if s==d:
        return 0

    q=queue.Queue()

    q.put(s);
    v[maps[s]] = 1


    while not q.empty():
        z = q.get()
         
        
        if z==d:
            return v[maps[z]]-1
        
        ho=maps[z]

        for i in range(len(z)):
            for j in range(ord('a'),ord('z')+1):
                if chr(j)==z[i]:
                    continue

                tmp = z[:i] + chr(j) + z[i+1:]

                if tmp not in maps:
                    continue;

                if v[maps[tmp]]!=0:
                    continue
                v[maps[tmp]]=v[ho ] + 1
                q.put(tmp)

 
def main():
    t =int(input())
    #s = input()

    for _ in range(t):
        global maps,mark
        mark = 1
        maps = dict() 

        while True:
            s = input()
            if s =="*":
                break
 
            maps[s]=mark
            mark+=1

 

        while True:
            s = input();

            if not s.strip():
                break;

            else:
                s= list(map(str,s.split(' ')))

                print (s[0],s[1],bfs(s[0],s[1]) )
        
        print ("")



main()
