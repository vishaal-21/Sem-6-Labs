import pandas as pd

df=pd.DataFrame({
    "Name":["Kuber","Vishal","Ram"],
    "Quiz_1 /10":[9,10,9],
    "In-sem_1 /15":[13,14,15],
    "Quiz_2 /10":[8,8.5,7],
    "In-sem_2 /15":[15,13,12.5]
    })

df["Total /50"]=df.loc[:,"Quiz_1 /10":"In-sem_2 /15"].sum(axis=1)
new_row=["Mean"]

for i in range(1,len(df.columns)):
    mean=df[df.columns[i]].mean()
    new_row.append(mean)
    
df.loc[len(df)]=new_row

print(df)