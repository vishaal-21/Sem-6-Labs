import numpy as np

A=np.arange(20).reshape(4,5)
print(A)
print("Sum of each column :",A.sum(axis=0))
print("Sum of each row :",A.sum(axis=1))