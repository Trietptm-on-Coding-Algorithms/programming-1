#!/usr/bin/python

import random

print '1003'
print '808'
print '2133'
print '234623'

for trial in range(1000):
    size = random.randint(1,100000)

    buf = ''
    for k in range(size):
        buf += str(random.randint(0,9))
    print buf
