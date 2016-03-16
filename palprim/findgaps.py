#!/usr/bin/env python

import sys

# input: list of [start,end] tuples
# generates if/then code with at most log_2(n) checks (where n is number of intervals)
def genIntervalCheckSmart(intervals, depth=0):
    if not intervals:
        return

    i = len(intervals)/2
    left = intervals[0:i]
    foo = intervals[i]
    right = intervals[i+1:]

    # root check
    print '%sif x>%d:' % ('    '*depth, foo[0])

    # right subcheck
    genIntervalCheck(intervals[i+1:], depth+1)

    # root right check
    print '%sif x<%d:' % ('    '*(depth+1), foo[1])
    print '%sreturn %d #located in [%d, %d]' % ('    '*(depth+2), foo[0], foo[0], foo[1])

    # left subcheck
    if left:
        print '%selse: #<%d' % ('    '*depth, foo[0])
        genIntervalCheck(intervals[0:i], depth+1)

# input: list of [start,end] tuples
def genIntervalCheck(intervals):
    for i in intervals:
        print "    if x>%d and x<%d: return %d; # interval_len=%d" % \
            (i[0], i[1], i[0], i[1]-i[0])
 
lang = 'python'
if sys.argv[1:]:
    lang = sys.argv[1]

last_prime = 2

intervals = []

# pplist.txt is decreasing (generate with search() in palprim.gp)
# eg:
# 91019
# 90709
# 79997
# 79697
# 79397
# 78887
# 78787

with open('pplist.txt') as f:
    for line in f:
        this_prime = int(line)

        # only interested in intervals sized > 1000 
        if (last_prime - this_prime) > 1000:
            intervals.append([this_prime, last_prime])

        last_prime = this_prime

# sort by interval size
intervals = sorted(intervals, key=lambda x: x[0], reverse=True)
# take top 128
intervals = intervals[0:128]
#for b in intervals:
#    print "at % 13d there's a run of %013d" % (runs[b]['start'], runs[b]['length'])

genIntervalCheckSmart(intervals)
genIntervalCheck(intervals)

   




