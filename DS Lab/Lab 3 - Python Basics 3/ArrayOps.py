import numpy as np

list=[6,45,20,19,11,34,28]
tuple=(1,2,3,4,5,6,7,8)

A=np.array(list)
print("A = ",A)

B=np.array(tuple).reshape((2,4))
print("B = ",B)

C=np.zeros((3,4))
print("C = ",C)

D=np.arange(0,20,5)
print("D = ",D)

E=C.reshape(2,2,3)
print("E = ",E)

print("Max and Min element of A :",A.max(),"and",A.min())
print("Row sum and column sum of B :",B.sum(axis=1),"and",B.sum(axis=0))