from __future__ import print_function
import sys

lastWord = None
word = None
sum = 0
word_count = {}
currMax = 0

for line in sys.stdin:
    parts = line.split("\t")
    
    if len(parts) == 2:
        word, count = parts
    else:
        continue

    count = int(count)

    if word == lastWord:
        sum += count
    else:
        if lastWord:
            word_count[lastWord] = sum
            print("%s\t%d" % (lastWord, sum))
            if sum > currMax:
                currMax = sum
        sum = count
        lastWord = word

if lastWord == word:
    word_count[lastWord] = sum
    print('%s\t%s' % (lastWord, sum))
    if sum > currMax:
        currMax = sum

# Finding words with the maximum frequency
freqWords = [key for key, value in word_count.items() if value == currMax]

print("Words with maximum frequency:", freqWords,":",currMax)
