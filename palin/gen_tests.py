#!/usr/bin/python

import random

print 3 + 10000 + 100

print '808'
print '2133'
print '234623'

for i in range(10000):
    print i

for trial in range(100):
    size = random.randint(1,100000)

    buf = ''
    for k in range(size):
        buf += str(random.randint(0,9))
    print buf
