filename=input("Enter name of file to be copied : ")
file1=open(filename,"r")
file_string=file1.read()

filename=input("Enter name of file to be copied to : ")
file2=open(filename,"w")
result=file_string[::-1]
file2.write(result)

