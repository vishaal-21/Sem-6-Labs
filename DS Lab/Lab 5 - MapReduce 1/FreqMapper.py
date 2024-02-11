from __future__ import print_function
import sys

lastWord = None
sum = 0

for line in sys.stdin:
    L = [ (word.strip(), 1 ) for word in line.strip().split('\t') ]
    for word, n in L:
        print( '%s\t%d' % (word, n) )