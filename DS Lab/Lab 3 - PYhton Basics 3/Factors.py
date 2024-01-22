n=int(input("Enter number : "))

print("Factors are : ",end=' ')

for i in range(1,n):
    if n%i==0:
        print(i,end=' ')