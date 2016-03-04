#!/usr/local/bin/python

import random

class PalindromeReverseIterator:
    def __init__(self, n):
        self.setAt(n)

    def setAt(self, n):
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

        # skip evens
        s = str(self.count)
        if n!=2 and s[0] in '2468':
            s = {'2':'1','4':'3','6':'5','8':'7'}[s[0]] + s[1:]
            self.count = int(s)

        #self.status()

    def status(self):
        print "  count: %d" % self.count
        print "  pivot: %d" % self.pivot
        print "limitLo: %d" % self.limitLo
        print "limitHi: %d" % self.limitHi
        print '--'

    def __iter__(self):
        return self

    def next(self):
        answer = ''
        
        # base case
        #print "WTF? count: %d" % self.count
        if self.count <= 0: raise StopIteration()

        # form answer
        s = str(self.count)
        if self.pivot:
            answer = s + (s[:-1])[::-1]
        else:
            answer = s + s[::-1]

        # where next?
        self.count -= 1

        if self.count < self.limitLo:
            if self.pivot:
                self.limitHi = self.limitLo - 1
                self.limitLo = (self.limitLo + 1) / 10
                self.count = self.limitHi
                self.pivot = False
            else:
                self.count = self.limitHi
                self.pivot = True
                self.pivot = True

        # skip evens
        s = str(self.count)
        if s[0] in '2468':
            s = {'2':'1','4':'3','6':'5','8':'7'}[s[0]] + s[1:]
            self.count = int(s)

        #self.status()

        # done
        return int(answer)

class PalindromeIterator:
    def __init__(self):
        self.count = 0
        self.limitLo = 0 # 1, 10, 100, etc.
        self.limitHi = 9 # 9, 99, 999, etc.
        self.pivot = True

    def __iter__(self):
        return self

    def next(self):
        answer = ''

        # form answer
        s = str(self.count)
        if self.pivot:
            answer = s + (s[:-1])[::-1]
        else:
            answer = s + s[::-1]

        # where next?
        self.count += 1
        if self.pivot:
            if self.count > self.limitHi:
                self.count = self.limitLo
                self.pivot = False
        else:
            if self.count > self.limitHi:
                self.limitLo = self.limitHi+1
                self.limitHi = 10*self.limitLo - 1

                self.count = self.limitLo
                self.pivot = True

        # done
        return int(answer)


def ExpMod(base, exp, modulus):
    answer = 1
    runner = base

    if not exp:
        return 1

    while 1:
        if exp & 1:
            answer = (answer*runner) % modulus

        exp = exp >> 1
        if not exp: break

        runner = (runner*runner) % modulus

    return answer

def isPalin(a):
    s = str(a)
    return s == s[::-1]

# Miller Rabin test
def isPrime(n):
    if n==2: return 1
    # reject even numbers that != 2
    if (n & 1) == 0:
        return 0

    #one = ZZn(1, n)
    #onel = ZZn(n-1, n)

    # now let's get into form n = 2^s * d + 1
    # s must be odd, which is automatically the case if we maximize r
    temp = n-1
    s = 0
    while temp % 2 == 0:
        s += 1
        temp /= 2
    d = temp

    #print "%d = 2^%d * %d + 1" % (n, s, d)

    # base test
    # at most N/4 bases will falsely report a likely prime
    for temp in range(4):
        #print "iteration %d" % temp
        base = random.randrange(1, n-1)

        #x = ZZn(base, n)**d
        x = ExpMod(base, d, n)
        #if x == one or x == onel:
        if x == 1 or x == n-1:
            continue
        
        #print "we don't have a witness! %d^%d != 1 (mod %d)" % (base, s, n)

        # otherwise...
        passing = 0
        for r in range(0,s):
            #x = x**2
            x = x*x
            if x == 1:
                #print "we don't have a pow2 witness! %d^%d == %s"
                return 0
            if x == n-1:
                #print "set passing"
                passing = 1
                break
            #print "next"
           
        if not passing: 
            return 0

    return 1

# main
#t = int(raw_input())
n = int(raw_input())
#print "%d trials" % n

for z in range(n):

    n = int(raw_input())
    if n!=2 and (n%2)==0: n-=1
    #print "making iterator with %d" % n
    it = iter(PalindromeReverseIterator(n))

    while 1:
        k = it.next()

        #print "checking primality of %d" % k
        if isPrime(k):
            print k
            break
        #print "done checking primality"



