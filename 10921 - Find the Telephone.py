#dictonory
a ={}
a['A'] = a['B'] = a['C'] = 2
a['D'] = a['E'] = a['F'] = 3
a['G'] = a['H'] = a['I'] = 4
a['J'] = a['K'] = a['L'] = 5
a['M'] = a['N'] = a['O'] = 6
a['P'] = a['Q'] = a['R'] = a['S'] = 7
a['T'] = a['U'] = a['V'] = 8
a['W'] = a['X'] = a['Y'] = a['Z'] = 9

#list
p = []

import sys

for line in sys.stdin: 
    for c in line:
        if( c.isalpha() ):
            p.append( a[c] )
        else :
            p.append( c ) # '\n' is appended too

for c in p:
    print(c, end='')
