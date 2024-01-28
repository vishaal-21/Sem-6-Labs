import pandas as pd

students={"Name":["Vishal","Kuber"],"Height":["6.2ft","Bohot chhota"],"Qualification":["Student","Also student"]}
df=pd.DataFrame(students)

address=["American","West Delhi"]
df["Address"]=address
print(df)