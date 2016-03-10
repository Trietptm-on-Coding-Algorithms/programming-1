#!/usr/bin/env python

# http://www.spoj.com/problems/PALIN/
# PALIN - The Next Palindrome

import sys

class PalindromeIterator:
    def __init__(self, n):
        self.setAt(n)

    def setAt(self, n):
        # precondition input

        log = 0
        s = str(n)
        if len(s) % 2:
            # odd
            log = len(s)/2
            self.count = int(s[0:log+1])
            self.pivot = True
        else:
            # even
            log = len(s)/2-1
            self.count = int(s[0:log+1])
            self.pivot = False

        self.limitLo = 10**log
        self.limitHi = 10**(log+1) - 1

        # cheap way to initialize
        while self.current() < n:
            self.next()

        #self.status()

    def status(self):
        print "  count: %d" % self.count
        print "  pivot: %d" % self.pivot
        print "limitLo: %d" % self.limitLo
        print "limitHi: %d" % self.limitHi
        print '--'

    def current(self):
        s = str(self.count)
        if self.pivot:
            return int(s + (s[:-1])[::-1])
        else:
            return int(s + s[::-1])

    def __iter__(self):
        return self

    def next(self):
        answer = self.current()

        # where next?
        self.count += 1

        if self.count > self.limitHi:
            if self.pivot:
                # just reset, unset pivot
                self.count = self.limitLo
                self.pivot = False
            else:
                # set new limits
                self.limitLo = self.limitLo * 10
                self.count = self.limitLo * 10 - 1
                self.pivot = True

        #self.status()

        # done
        return int(answer)

n = int(raw_input())

for z in range(n):
    k = 0
    try:
        k = int(raw_input())
    except:
        break
    
    it = iter(PalindromeIterator(k))
    while it.current() <= k:
        it.next()

    print it.current()

sys.exit(0)

