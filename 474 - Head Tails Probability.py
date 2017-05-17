import sys
import math

ans_list = []

def ppow(n):
    start = 1
    ans = 1
    
    ans_len = len(ans_list)
    if( ans_len > 0 ):
        start = ans_len + 1    
        ans = ans_list[ans_len-1]
    if( n < ans_len):
        return ans_list[n-1]
        
    for i in range(start,n+1):
        ans = ans /2
        while(ans<1):
            ans = ans * 10
        ans_list.append(ans)
    return ans

for n in sys.stdin:
    n = int(n)
    ans = ppow(n)
    out = str( '{:.4}'.format(ans) )
    while( len(out) < 5 ):
        out = out+'0'
    print('2^-'+str(n)+' = '+out+'e'+str(math.floor( math.log10(1/2) * n )) )
