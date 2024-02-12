import sys

for line in sys.stdin:
    line=line.strip().split(',')
    
    if len(line)==8:
        place,conf=line[3],line[5]
    else:
        continue
    
    print('%s\t%s'%(place,conf))