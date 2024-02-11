import sys

for line in sys.stdin:
    line=line.strip().split('\t')
    
    age,salary=line[2],line[19]
    print( '%s\t%s' %(age,salary))