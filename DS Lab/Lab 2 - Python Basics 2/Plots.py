import pandas as pd
import matplotlib.pyplot as plt

filepath="/mnt/c/Users/Visha/OneDrive/Documents/Sem-6-Labs/DS Lab/Datasets/xyz.csv"         

df=pd.read_csv(filepath,header=None)
df.columns=list('abcdefghi')

plt.scatter(df['f'],df['b'])
plt.xlabel('f')
plt.ylabel('b')
plt.savefig('scatter.png')

plt.plot(df['f'],df['b'])
plt.xlabel('f')
plt.ylabel('b')
plt.savefig('line.png')

plt.hist(df['h'])
plt.savefig('hist.png')

plt.bar(df['f'],df['b'])
plt.xlabel("Some")
plt.ylabel("Something")
plt.savefig('bar.png')

data=[10,15,25,30,5,5,5,5]
categories=list('12345678')
plt.pie(data,labels=categories,autopct='%1.1f%%')
plt.savefig('pie.png')

plt.boxplot(data)
plt.savefig('box.png')