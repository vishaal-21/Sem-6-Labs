class Power():
    def pow(self,x,n):
        res=1;
        for i in range(n):
            res*=x

        return res

x=int(input("Enter base value : "))
n=int(input("Enter exponent : "))

obj=Power()
res=obj.pow(x,n)
print("Answer = ",res)