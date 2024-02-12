import sys

for line in sys.stdin:
    line=line.strip().split('\t')
    
    if len(line)==6:
        item,price=line[2],line[4]
    else:
        continue
    
    print('%s\t%s'%(item,price))