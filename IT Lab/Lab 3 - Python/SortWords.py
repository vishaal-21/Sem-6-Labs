list=[]

print("Enter words (-1 to stop) : ")
name=input();

while(name!='-1'):
    list.append(name)
    name=input()

list.sort()
print(list)