import sys
from operator import itemgetter

currWord = None
word=None
currCount = 0
counts={}

for line in sys.stdin:
    line = line.strip()

    parts = line.split("\t")
    
    if len(parts) == 2:
        word, count = parts
    else:
        continue

    try:
        count = int(count)
    except ValueError:
        continue

    if currWord == word:
        currCount += count
    else:
        if currWord:
            counts[currWord]=currCount
        currWord = word
        currCount = count

if currWord:
    counts[currWord]=currCount

for key, value in sorted(counts.items()):
    print(f"{key} : {value}")

categories=list(counts.keys())
values=list(counts.values())

plt.pie(values,labels=categories)
plt.show()
