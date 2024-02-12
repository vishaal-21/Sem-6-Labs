import sys
from operator import itemgetter

currWord = None
word=None
currCount = 0

for line in sys.stdin:
    line = line.strip()

    parts = line.split("-")
    
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
            print( '%s - %s' %(currWord,currCount))
        currWord = word
        currCount = count

if currWord:
    print( '%s-%s' %(currWord,currCount))