#!/usr/bin/env python

import random

def skipGaps(x):
    if x>9989899 and x<100030001: return 9989899 # interval_len=90040102
    if x>199999991 and x<300020003: return 199999991 # interval_len=100020012
    if x>399878993 and x<700020007: return 399878993 # interval_len=300141014
    if x>799959997 and x<900010009: return 799959997 # interval_len=100050012
    if x>999727999 and x<10000500001: return 999727999 # interval_len=9000772002
    if x>19998289991 and x<30000500003: return 19998289991 # interval_len=10002210012
    if x>39998389993 and x<70005450007: return 39998389993 # interval_len=30007060014
    if x>79998589997 and x<90000200009: return 79998589997 # interval_len=10001610012
    if x>99999199999 and x<1000008000001: return 99999199999 # interval_len=900008800002
    if x>1021638361201 and x<1021737371201: return 1021638361201 # interval_len=99010000
    if x>1041465641401 and x<1041550551401: return 1041465641401 # interval_len=84910000
    if x>1055273725501 and x<1055360635501: return 1055273725501 # interval_len=86910000
    if x>1079554559701 and x<1079647469701: return 1079554559701 # interval_len=92910000
    if x>1114265624111 and x<1114360634111: return 1114265624111 # interval_len=95010000
    if x>1125572755211 and x<1125656565211: return 1125572755211 # interval_len=83810000
    if x>1134520254311 and x<1134604064311: return 1134520254311 # interval_len=83810000
    if x>1138614168311 and x<1138712178311: return 1138614168311 # interval_len=98010000
    if x>1182067602811 and x<1182163612811: return 1182067602811 # interval_len=96010000
    if x>1272727272721 and x<1272815182721: return 1272727272721 # interval_len=87910000
    if x>1316161616131 and x<1316290926131: return 1316161616131 # interval_len=129310000
    if x>1405161615041 and x<1405253525041: return 1405161615041 # interval_len=91910000
    if x>1436876786341 and x<1436980896341: return 1436876786341 # interval_len=104110000
    if x>1437594957341 and x<1437681867341: return 1437594957341 # interval_len=86910000
    if x>1507011107051 and x<1507103017051: return 1507011107051 # interval_len=91910000
    if x>1588279728851 and x<1588369638851: return 1588279728851 # interval_len=89910000
    if x>1614427244161 and x<1614534354161: return 1614427244161 # interval_len=107110000
    if x>1626654566261 and x<1626747476261: return 1626654566261 # interval_len=92910000
    if x>1730249420371 and x<1730334330371: return 1730249420371 # interval_len=84910000
    if x>1780990990871 and x<1781090901871: return 1780990990871 # interval_len=99911000
    if x>1821307031281 and x<1821408041281: return 1821307031281 # interval_len=101010000
    if x>1859959599581 and x<1860083800681: return 1859959599581 # interval_len=124201100
    if x>1878686868781 and x<1878781878781: return 1878686868781 # interval_len=95010000
    if x>1916320236191 and x<1916410146191: return 1916320236191 # interval_len=89910000
    if x>1964115114691 and x<1964203024691: return 1964115114691 # interval_len=87910000
    if x>1999987899991 and x<3000002000003: return 1999987899991 # interval_len=1000014100012
    if x>3025212125203 and x<3025322235203: return 3025212125203 # interval_len=110110000
    if x>3039218129303 and x<3039308039303: return 3039218129303 # interval_len=89910000
    if x>3122986892213 and x<3123091903213: return 3122986892213 # interval_len=105011000
    if x>3240488840423 and x<3240582850423: return 3240488840423 # interval_len=94010000
    if x>3245839385423 and x<3245958595423: return 3245839385423 # interval_len=119210000
    if x>3248241428423 and x<3248325238423: return 3248241428423 # interval_len=83810000
    if x>3259782879523 and x<3259867689523: return 3259782879523 # interval_len=84810000
    if x>3268679768623 and x<3268764678623: return 3268679768623 # interval_len=84910000
    if x>3293838383923 and x<3293922293923: return 3293838383923 # interval_len=83910000
    if x>3354236324533 and x<3354324234533: return 3354236324533 # interval_len=87910000
    if x>3361549451633 and x<3361635361633: return 3361549451633 # interval_len=85910000
    if x>3388371738833 and x<3388459548833: return 3388371738833 # interval_len=87810000
    if x>3444353534443 and x<3444444444443: return 3444353534443 # interval_len=90910000
    if x>3505005005053 and x<3505092905053: return 3505005005053 # interval_len=87900000
    if x>3512000002153 and x<3512099902153: return 3512000002153 # interval_len=99900000
    if x>3522152512253 and x<3522239322253: return 3522152512253 # interval_len=86810000
    if x>3550987890553 and x<3551071701553: return 3550987890553 # interval_len=83811000
    if x>3598644468953 and x<3598729278953: return 3598644468953 # interval_len=84810000
    if x>3626484846263 and x<3626585856263: return 3626484846263 # interval_len=101010000
    if x>3740459540473 and x<3740570750473: return 3740459540473 # interval_len=111210000
    if x>3750512150573 and x<3750597950573: return 3750512150573 # interval_len=85800000
    if x>3787903097873 and x<3787995997873: return 3787903097873 # interval_len=92900000
    if x>3875738375783 and x<3875827285783: return 3875738375783 # interval_len=88910000
    if x>3927162617293 and x<3927275727293: return 3927162617293 # interval_len=113110000
    if x>3942806082493 and x<3942899982493: return 3942806082493 # interval_len=93900000
    if x>3999627269993 and x<3999713179993: return 3999627269993 # interval_len=85910000
    if x>3999992999993 and x<7000005000007: return 3999992999993 # interval_len=3000012000014
    if x>7001003001007 and x<7001094901007: return 7001003001007 # interval_len=91900000
    if x>7019990999107 and x<7020084800207: return 7019990999107 # interval_len=93801100
    if x>7038972798307 and x<7039057509307: return 7038972798307 # interval_len=84711000
    if x>7045928295407 and x<7046022206407: return 7045928295407 # interval_len=93911000
    if x>7047012107407 and x<7047095907407: return 7047012107407 # interval_len=83800000
    if x>7096130316907 and x<7096219126907: return 7096130316907 # interval_len=88810000
    if x>7099578759907 and x<7099676769907: return 7099578759907 # interval_len=98010000
    if x>7252502052527 and x<7252613162527: return 7252502052527 # interval_len=111110000
    if x>7263061603627 and x<7263149413627: return 7263061603627 # interval_len=87810000
    if x>7272878782727 and x<7272964692727: return 7272878782727 # interval_len=85910000
    if x>7287387837827 and x<7287479747827: return 7287387837827 # interval_len=91910000
    if x>7306892986037 and x<7306996996037: return 7306892986037 # interval_len=104010000
    if x>7329552559237 and x<7329638369237: return 7329552559237 # interval_len=85810000
    if x>7380915190837 and x<7381009001837: return 7380915190837 # interval_len=93811000
    if x>7426371736247 and x<7426460646247: return 7426371736247 # interval_len=88910000
    if x>7472247422747 and x<7472333332747: return 7472247422747 # interval_len=85910000
    if x>7502150512057 and x<7502236322057: return 7502150512057 # interval_len=85810000
    if x>7539539359357 and x<7539623269357: return 7539539359357 # interval_len=83910000
    if x>7553420243557 and x<7553508053557: return 7553420243557 # interval_len=87810000
    if x>7554169614557 and x<7554256524557: return 7554169614557 # interval_len=86910000
    if x>7596822286957 and x<7596908096957: return 7596822286957 # interval_len=85810000
    if x>7598977798957 and x<7599095909957: return 7598977798957 # interval_len=118111000
    if x>7603718173067 and x<7603804083067: return 7603718173067 # interval_len=85910000
    if x>7634405044367 and x<7634494944367: return 7634405044367 # interval_len=89900000
    if x>7643015103467 and x<7643102013467: return 7643015103467 # interval_len=86910000
    if x>7714674764177 and x<7714758574177: return 7714674764177 # interval_len=83810000
    if x>7744499944477 and x<7744587854477: return 7744499944477 # interval_len=87910000
    if x>7815061605187 and x<7815158515187: return 7815061605187 # interval_len=96910000
    if x>7818318138187 and x<7818419148187: return 7818318138187 # interval_len=101010000
    if x>7893225223987 and x<7893326233987: return 7893225223987 # interval_len=101010000
    if x>7911324231197 and x<7911413141197: return 7911324231197 # interval_len=88910000
    if x>7990371730997 and x<7990455540997: return 7990371730997 # interval_len=83810000
    if x>7999992999997 and x<9000005000009: return 7999992999997 # interval_len=1000012000012
    if x>9055968695509 and x<9056063606509: return 9055968695509 # interval_len=94911000
    if x>9068952598609 and x<9069038309609: return 9068952598609 # interval_len=85711000
    if x>9077584857709 and x<9077677767709: return 9077584857709 # interval_len=92910000
    if x>9082892982809 and x<9082984892809: return 9082892982809 # interval_len=91910000
    if x>9104206024019 and x<9104290924019: return 9104206024019 # interval_len=84900000
    if x>9189091909819 and x<9189182819819: return 9189091909819 # interval_len=90910000
    if x>9217970797129 and x<9218088808129: return 9217970797129 # interval_len=118011000
    if x>9291891981929 and x<9291978791929: return 9291891981929 # interval_len=86810000
    if x>9301158511039 and x<9301243421039: return 9301158511039 # interval_len=84910000
    if x>9343898983439 and x<9343985893439: return 9343898983439 # interval_len=86910000
    if x>9352254522539 and x<9352368632539: return 9352254522539 # interval_len=114110000
    if x>9381629261839 and x<9381717171839: return 9381629261839 # interval_len=87910000
    if x>9382782872839 and x<9382911192839: return 9382782872839 # interval_len=128320000
    if x>9414706074149 and x<9414804084149: return 9414706074149 # interval_len=98010000
    if x>9462147412649 and x<9462233322649: return 9462147412649 # interval_len=85910000
    if x>9502466642059 and x<9502578752059: return 9502466642059 # interval_len=112110000
    if x>9504203024059 and x<9504297924059: return 9504203024059 # interval_len=94900000
    if x>9521129211259 and x<9521217121259: return 9521129211259 # interval_len=87910000
    if x>9561550551659 and x<9561642461659: return 9561550551659 # interval_len=91910000
    if x>9585315135859 and x<9585403045859: return 9585315135859 # interval_len=87910000
    if x>9680260620869 and x<9680356530869: return 9680260620869 # interval_len=95910000
    if x>9680690960869 and x<9680773770869: return 9680690960869 # interval_len=82810000
    if x>9706147416079 and x<9706234326079: return 9706147416079 # interval_len=86910000
    if x>9741239321479 and x<9741335331479: return 9741239321479 # interval_len=96010000
    if x>9749101019479 and x<9749191919479: return 9749101019479 # interval_len=90900000
    if x>9789768679879 and x<9789858589879: return 9789768679879 # interval_len=89910000
    if x>9817766677189 and x<9817850587189: return 9817766677189 # interval_len=83910000
    if x>9866762676689 and x<9866863686689: return 9866762676689 # interval_len=101010000
    if x>9868480848689 and x<9868573758689: return 9868480848689 # interval_len=92910000
    if x>9899025209989 and x<9899121219989: return 9899025209989 # interval_len=96010000
    if x>9912130312199 and x<9912261622199: return 9912130312199 # interval_len=131310000
    if x>9914907094199 and x<9914991994199: return 9914907094199 # interval_len=84900000
    if x>9963023203699 and x<9963114113699: return 9963023203699 # interval_len=90910000
    return 0

class PalindromeReverseIterator:
    def __init__(self, n):
        self.initialize(n)

    def initialize(self, n):
        # optimize

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

        # if it's already a palindrome, prime for the next() call
        if s == s[::-1]:
            self.count += 1

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
        self.count -= 1

        if self.count < self.limitLo:
            if self.pivot:
                if self.count < 2:
                    raise StopIteration()

                self.pivot = 0
                self.limitHi = self.limitLo - 1
                self.limitLo = self.limitLo / 10
            else:
                self.pivot = 1

            self.count = self.limitHi

        # form answer
        s = str(self.count)
        if self.pivot:
            return int(s + (s[:-1])[::-1])
        else:
            return int(s + s[::-1])

def witness(n, s, d, a):
    x = pow(a, d, n) # a^d
    if x == 1 or x==(n-1): return False
       
    # try all a^(2*d), a^(2^2*d), a^(2^3*d), ..., a^(2^s*d)
    for i in range(s):
        x = pow(x, 2, n)
        if x == n-1: return False

    return True
 
def is_prime_mr(n):

    d = (n-1) / 2
    s = 1
    while not (d & 1):
        d >>= 1
        ++s

    # two witness case
    if n < 9080191:
        return not witness(n,s,d,31) and not witness(n,s,d,73)
    # three witness case
    if n < 4759123141:
        return not witness(n,s,d,2) and not witness(n,s,d,7) and not witness(n,s,d,61)
    # four witness case
    if n < 1122004669633:
        return not witness(n,s,d,2) and not witness(n,s,d,13) and not witness(n,s,d,23) and not witness(n,s,d,1662803)
    # 5
    if n < 2152302898747:
        return not witness(n,s,d,2) and not witness(n,s,d,3) and not witness(n,s,d,5) and not witness(n,s,d,7) and not witness(n,s,d,11)
    # 6
    if n < 3474749660383:
        return not witness(n,s,d,2) and not witness(n,s,d,3) and not witness(n,s,d,5) and not witness(n,s,d,7) and not witness(n,s,d,11) and not witness(n,s,d,13)
    # 7
    return not witness(n,s,d,2) and not witness(n,s,d,3) and not witness(n,s,d,5) and not witness(n,s,d,7) and not witness(n,s,d,11) and not witness(n,s,d,13) and not witness(n,s,d,17)

def isPrime(num):
    # Return True if num is a prime number. This function does a quicker
    # prime number check before calling rabinMiller().
    
    if (num < 2):
        return False # 0, 1, and negative numbers are not prime

    # About 1/3 of the time we can quickly determine if num is not prime
    # by dividing by the first few dozen prime numbers. This is quicker
    # than rabinMiller(), but unlike rabinMiller() is not guaranteed to
    # prove that a number is prime.
    lowPrimes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]

    if num in lowPrimes:
        return True

    # See if any of the low prime numbers can divide num
    for prime in lowPrimes:
        if (num % prime == 0):
            return False

    # If all else fails, call rabinMiller() to determine if num is a prime.
    return is_prime_mr(num)

#
# main
#
if __name__ == '__main__':
    if 1:
        n = int(raw_input())
    
        for z in range(n):
    
            n = int(raw_input())
            
            tmp = skipGaps(n)
            if tmp:
                print tmp
            else:
                #print "making iterator with %d" % n
                it = iter(PalindromeReverseIterator(n))
        
                while 1:
                    k = it.next()
        
                    #print "checking primality of %d" % k
                    if isPrime(k):
                        print k
                        break
                        #print "done checking primality"
    else:
        it = iter(PalindromeReverseIterator(9999999999999))
        #it = iter(PalindromeReverseIterator(9999999999))
        #it = iter(PalindromeReverseIterator(1000330001))
        for p in it:
            print p
    

