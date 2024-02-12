import sys

maxCases=cases=0
currPlace=place=None

for line in sys.stdin:
    line=line.strip().split('\t')
    
    if len(line)==2:
        place,conf=line
    else:
        continue
    
    try:
        conf=int(conf)
    except ValueError:
        continue
    
    if currPlace==place:
        if conf>maxCases:
            maxCases=conf
    else:
        if currPlace:
            print("Max number of cases for %s is %d" %(currPlace,maxCases))
        currPlace=place
        maxCases=0
        
if currPlace:
    print("Max number of cases for %s is %d" %(currPlace,maxCases))