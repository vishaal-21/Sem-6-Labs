import sys

oddcount=evencount=0
nums=sys.stdin.read().strip().split('\t')
print(nums)

for num in nums:
    if int(num)%2==0:
        oddcount+=1
    else:
        evencount+=1
        
print("Number of odd values = ",oddcount)
print("Number of even values = ",evencount)