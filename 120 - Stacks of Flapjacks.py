import sys

#list
e = []
p = []

while(1):
    t  = sys.stdin.readline()
    s = t.strip(' \n')
    if( len(s) <= 0 ):
        break
    e = (s).split(' ')
    p =[]

    #char to int
    f = 0;
    for k in e:
        if(f==0):
            print( int(k), end='')
            f = 1
        else:
            print( '',int(k), end='')
        p.append( int(k) )
    print() # print a \n

    len_p = a = len(p)
    while(a>0):
        max_num = max(p[0:a])
        max_idx = p[0:a].index(max_num)
        if( max_idx != a-1 ):
            if( max_idx != 0 ):
                #reverse [s,max_idx/2]
                s = 0
                while(s<=int(max_idx/2)):
                    p[s] , p[max_idx-s]= p[max_idx-s] , p[s]
                    s = s+1
                print(len_p-max_idx, end=' ')
            #reverse [s,(a-1)/2)]   
            s = 0
            while(s<=int(((a-1)/2))):
                p[s] , p[a-s-1]= p[a-s-1] , p[s]
                s = s+1
            print(len_p-a+1, end=' ')
        a = a-1
    print(0)
