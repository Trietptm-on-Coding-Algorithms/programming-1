#!/usr/bin/env python

import re

fp = open('survey.txt', 'r')
lines = fp.readlines()
fp.close()

cur_int_start = 0
cur_int_len = 0
state = 'looking'

runs = {}

for line in lines:
    line = line.strip()
    #print "[state:%s] %s" % (state, line)
    m = re.match(r'^(\d+).*', line)
    here = int(m.group(1))

    if state=='looking':
        if line[-1] != 'X':
            cur_int_start = here
            state = 'in'
        continue

    if state == 'in':
        if line[-1] == 'X':
            info = {
                'start':cur_int_start,
                'length':cur_int_len
            }
            runs[cur_int_start] = info
            #print "at %d there's a run of %d" % (runs['start'], runs['length'])
            state = 'looking'
        else:
            cur_int_len = here - cur_int_start

best = sorted(runs.keys(), key=lambda x: runs[x], reverse=True)
for b in best[0:2048]:
    print "at % 13d there's a run of %013d" % (runs[b]['start'], runs[b]['length'])



