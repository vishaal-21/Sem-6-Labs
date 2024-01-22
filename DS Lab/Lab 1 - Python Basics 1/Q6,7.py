tuple=(1,3,5,7,9,2,4,6,8,10)
print(tuple[:len(tuple)//2:])
print(tuple[(len(tuple)//2)+1::])

new_t=()

for num in tuple:
    if num%2==0:
        new_t+=(num,)
        
print("New tuple",new_t)