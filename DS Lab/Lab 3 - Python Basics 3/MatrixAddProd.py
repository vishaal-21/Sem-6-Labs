import numpy as np

A=np.arange(15).reshape((3,5))
print(A)

B=np.arange(15).reshape((3,5))**2
print(B)

C=A+B
D=A*B
print("Sum\n",C)
print("Element wise product\n",D)