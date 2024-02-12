import sys
import random

nums=[random.randint(1,100) for _ in  range(13)]

for num in nums:
    print(num,end='\t')