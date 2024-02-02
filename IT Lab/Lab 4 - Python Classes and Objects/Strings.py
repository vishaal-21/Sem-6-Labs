class String:
    str=""
    def get_String(self):
        self.str=input("Enter a string : ")

    def put_String(self):
        print("String entered is :",self.str)

obj=String()
obj.get_String()
obj.put_String()