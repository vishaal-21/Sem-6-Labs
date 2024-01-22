list=[11,-21,0,18,-45,66,-93]
negcount=poscount=0
print(list)

for num in list:
    if num<0:
        negcount+=1
        print(num,end=' ')
    else:
        list.remove(num)
        poscount+=1
        
print("\nNegative:",negcount)
print("Positive:",poscount)

print(list)