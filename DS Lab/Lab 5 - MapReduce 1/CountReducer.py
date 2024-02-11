import sys

# currPlace=None
# item=None
# currPrice=0
totalAge=totalSalary=people=0

for line in sys.stdin:
    line=line.strip().split('\t')

    if len(line)==2:
        age,salary=line
    else: 
        continue
    
    try:
        age=int(age)
        salary=int(salary)
    except ValueError:
        continue

    totalAge+=age
    totalSalary+=salary
    people+=1

print("Total number of employees = %d" %people)
print("Average age = %d" %round(totalAge/people))
print("Average monthly salary = %d" %round(totalSalary/people))
    