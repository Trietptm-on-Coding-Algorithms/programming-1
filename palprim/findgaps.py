#!/usr/bin/env python

last_prime = 2

runs = {}

# generate pplist.txt with search() in palprim.gp
with open('pplist.txt') as f:
    for line in f:
        this_prime = int(line)

        run_len = last_prime - this_prime

        if run_len > 1000:
            info = {
                'start':this_prime,
                'length':run_len,
            }
            runs[this_prime] = info

        last_prime = this_prime

best = sorted(runs.keys(), key=lambda x: runs[x], reverse=True)
best = best[0:128]
for b in best:
    print "at % 13d there's a run of %013d" % (runs[b]['start'], runs[b]['length'])

# generate code for quick skipping of gaps
best = sorted(best)
for b in best:
    left_prime = runs[b]['start']
    right_prime = left_prime + runs[b]['length']

    print "    if(x>%dull and x<%dull) return %dull; // interval_len=%d" % \
        (left_prime, right_prime, left_prime, right_prime-left_prime)



