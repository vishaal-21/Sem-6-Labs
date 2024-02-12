import sys

currPlace=place=maxPlace=None
currPrice=price=0
maxPrice=0

for line in sys.stdin:
    line=line.strip().split('\t')
    
    if len(line)==2:
        place,price=line
    else:
        continue
    
    try:
        price=float(price)
    except ValueError:
        continue
    
    if currPlace==place:
        currPrice+=price
    else:
        if currPlace:
            print('%s\t%.2lf' %(currPlace,currPrice))
            if currPrice>maxPrice:
                maxPrice=currPrice
                maxPlace=currPlace
        currPrice=price
        currPlace=place
        
if currPlace:
    print('%s\t%.2lf' %(currPlace,currPrice))
    if currPrice>maxPrice:
        maxPrice=currPrice
        maxPlace=currPlace
        
print("Max Price = %.2lf in %s" %(maxPrice,maxPlace))