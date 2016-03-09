#!/usr/bin/env python

last_prime = 2

runs = {}

# generate pplist.txt with search() in palprim.gp
with open('pplist.txt') as f:
    for line in f:
        this_prime = int(line)

        run_len = this_prime - last_prime

        if run_len > 1000:
            info = {
                'start':last_prime,
                'length':run_len,
            }
            runs[last_prime] = info

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

    # convert the palindrome boundaries to "count" boundaries
    left_prime_ = str(left_prime)
    left_prime_ = int(left_prime_[0:len(left_prime_)/2+1])

    right_prime_ = str(right_prime)
    right_prime_ = int(right_prime_[0:len(right_prime_)/2+1])

    print "    if x>%d and x<%d: return %d # for [%d,%d] len=%d" % \
        (left_prime_, right_prime_, left_prime_, left_prime, right_prime, right_prime-left_prime)



