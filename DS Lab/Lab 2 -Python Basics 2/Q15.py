import pandas as pd
df1=pd.DataFrame({"Name":["Ram","Krishna","Shiva"]})
print(df1)

df2=pd.DataFrame({"Maths":[80,81,90],"Physics":[90,75,80],"Chemistry":[95,90,88],"Biology":[78,84,81]})
print(df2)

df_new=pd.concat([df1,df2],axis=1)

df_new["Total"]=df_new["Physics"]+df_new["Biology"]+df_new["Chemistry"]+df_new["Maths"]
print(df_new)