a=int(input("Enter first number : "))
b=int(input("Enter second number : "))
ch=input("Enter operator (+,-,*,/) : ")

if ch=='+':
	res=a+b
elif ch=='-':
	res=a-b
elif ch=='*':
	res=a*b
elif ch=='/':
	if b==0:
		print("Error")
	else:
		res=a/b

print("Result is",res)