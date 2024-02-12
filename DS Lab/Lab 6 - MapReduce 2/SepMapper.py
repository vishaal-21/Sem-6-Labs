import sys

for line in sys.stdin:
    line=line.strip()
    words=line.split('\t')

    for word in words:
        print("%s-%d" %(word,1)) 