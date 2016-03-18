#!/usr/bin/env python

import re
import sys
import random
import itertools

count = 0

edges = {}
deleted = {}

def dist(left, right):
    if(type(left) == type(right) == type(1)):
        left = int(left)
        right = int(right)

    if len(left) != len(right):
        raise Exception("comparing %s to %s" % (left, right))

    dist = 0
    for i in range(len(left)):
        if left[i] != right[i]:
            dist += 1

    return dist

symList = 'ABCD'
nodeLen = 3 

allNodes = [''.join(x) for x in itertools.product(symList, repeat=nodeLen)]
#random.shuffle(allNodes)
for a in allNodes:
    for b in allNodes:
        d = dist(a,b)

        if d == 1:
            # add edge (sorted, into dict to avoid double edge)
            tmp = '"%s" -- "%s"' % tuple(sorted([a, b]))
            edges[tmp] = 1

            if not a in deleted:
                print '// inclusion of %s discludes %s' % (a,b)
                deleted[b] = 1
    
print '// total nodes: %d' % len(allNodes)
print '// total allowed: %d' % (len(allNodes) - len(deleted))
print '// total deleted: %d' % len(deleted)
print 'graph stuff {'
for e in edges.keys():
    print '    ', e

for n in allNodes:
    if n in deleted:
        print "    \"%s\" [style=filled, fillcolor=red]" % n
    else:
        print "    \"%s\" [style=filled, fillcolor=green]" % n
print '}'
