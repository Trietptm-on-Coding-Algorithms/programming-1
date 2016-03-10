#!/usr/bin/env python

import random

def skipGaps(x):
    if x>9989 and x<10003: return 9989 # for [9989899,100030001] len=90040102
    if x>19999 and x<30002: return 19999 # for [199999991,300020003] len=100020012
    if x>39987 and x<70002: return 39987 # for [399878993,700020007] len=300141014
    if x>79995 and x<90001: return 79995 # for [799959997,900010009] len=100050012
    if x>99972 and x<100005: return 99972 # for [999727999,10000500001] len=9000772002
    if x>199982 and x<300005: return 199982 # for [19998289991,30000500003] len=10002210012
    if x>399983 and x<700054: return 399983 # for [39998389993,70005450007] len=30007060014
    if x>799985 and x<900002: return 799985 # for [79998589997,90000200009] len=10001610012
    if x>999991 and x<1000008: return 999991 # for [99999199999,1000008000001] len=900008800002
    if x>1021638 and x<1021737: return 1021638 # for [1021638361201,1021737371201] len=99010000
    if x>1041465 and x<1041550: return 1041465 # for [1041465641401,1041550551401] len=84910000
    if x>1055273 and x<1055360: return 1055273 # for [1055273725501,1055360635501] len=86910000
    if x>1079554 and x<1079647: return 1079554 # for [1079554559701,1079647469701] len=92910000
    if x>1114265 and x<1114360: return 1114265 # for [1114265624111,1114360634111] len=95010000
    if x>1125572 and x<1125656: return 1125572 # for [1125572755211,1125656565211] len=83810000
    if x>1134520 and x<1134604: return 1134520 # for [1134520254311,1134604064311] len=83810000
    if x>1138614 and x<1138712: return 1138614 # for [1138614168311,1138712178311] len=98010000
    if x>1182067 and x<1182163: return 1182067 # for [1182067602811,1182163612811] len=96010000
    if x>1272727 and x<1272815: return 1272727 # for [1272727272721,1272815182721] len=87910000
    if x>1316161 and x<1316290: return 1316161 # for [1316161616131,1316290926131] len=129310000
    if x>1405161 and x<1405253: return 1405161 # for [1405161615041,1405253525041] len=91910000
    if x>1436876 and x<1436980: return 1436876 # for [1436876786341,1436980896341] len=104110000
    if x>1437594 and x<1437681: return 1437594 # for [1437594957341,1437681867341] len=86910000
    if x>1507011 and x<1507103: return 1507011 # for [1507011107051,1507103017051] len=91910000
    if x>1588279 and x<1588369: return 1588279 # for [1588279728851,1588369638851] len=89910000
    if x>1614427 and x<1614534: return 1614427 # for [1614427244161,1614534354161] len=107110000
    if x>1626654 and x<1626747: return 1626654 # for [1626654566261,1626747476261] len=92910000
    if x>1730249 and x<1730334: return 1730249 # for [1730249420371,1730334330371] len=84910000
    if x>1780990 and x<1781090: return 1780990 # for [1780990990871,1781090901871] len=99911000
    if x>1821307 and x<1821408: return 1821307 # for [1821307031281,1821408041281] len=101010000
    if x>1859959 and x<1860083: return 1859959 # for [1859959599581,1860083800681] len=124201100
    if x>1878686 and x<1878781: return 1878686 # for [1878686868781,1878781878781] len=95010000
    if x>1916320 and x<1916410: return 1916320 # for [1916320236191,1916410146191] len=89910000
    if x>1964115 and x<1964203: return 1964115 # for [1964115114691,1964203024691] len=87910000
    if x>1999987 and x<3000002: return 1999987 # for [1999987899991,3000002000003] len=1000014100012
    if x>3025212 and x<3025322: return 3025212 # for [3025212125203,3025322235203] len=110110000
    if x>3039218 and x<3039308: return 3039218 # for [3039218129303,3039308039303] len=89910000
    if x>3122986 and x<3123091: return 3122986 # for [3122986892213,3123091903213] len=105011000
    if x>3240488 and x<3240582: return 3240488 # for [3240488840423,3240582850423] len=94010000
    if x>3245839 and x<3245958: return 3245839 # for [3245839385423,3245958595423] len=119210000
    if x>3248241 and x<3248325: return 3248241 # for [3248241428423,3248325238423] len=83810000
    if x>3259782 and x<3259867: return 3259782 # for [3259782879523,3259867689523] len=84810000
    if x>3268679 and x<3268764: return 3268679 # for [3268679768623,3268764678623] len=84910000
    if x>3293838 and x<3293922: return 3293838 # for [3293838383923,3293922293923] len=83910000
    if x>3354236 and x<3354324: return 3354236 # for [3354236324533,3354324234533] len=87910000
    if x>3361549 and x<3361635: return 3361549 # for [3361549451633,3361635361633] len=85910000
    if x>3388371 and x<3388459: return 3388371 # for [3388371738833,3388459548833] len=87810000
    if x>3444353 and x<3444444: return 3444353 # for [3444353534443,3444444444443] len=90910000
    if x>3505005 and x<3505092: return 3505005 # for [3505005005053,3505092905053] len=87900000
    if x>3512000 and x<3512099: return 3512000 # for [3512000002153,3512099902153] len=99900000
    if x>3522152 and x<3522239: return 3522152 # for [3522152512253,3522239322253] len=86810000
    if x>3550987 and x<3551071: return 3550987 # for [3550987890553,3551071701553] len=83811000
    if x>3598644 and x<3598729: return 3598644 # for [3598644468953,3598729278953] len=84810000
    if x>3626484 and x<3626585: return 3626484 # for [3626484846263,3626585856263] len=101010000
    if x>3740459 and x<3740570: return 3740459 # for [3740459540473,3740570750473] len=111210000
    if x>3750512 and x<3750597: return 3750512 # for [3750512150573,3750597950573] len=85800000
    if x>3787903 and x<3787995: return 3787903 # for [3787903097873,3787995997873] len=92900000
    if x>3875738 and x<3875827: return 3875738 # for [3875738375783,3875827285783] len=88910000
    if x>3927162 and x<3927275: return 3927162 # for [3927162617293,3927275727293] len=113110000
    if x>3942806 and x<3942899: return 3942806 # for [3942806082493,3942899982493] len=93900000
    if x>3999627 and x<3999713: return 3999627 # for [3999627269993,3999713179993] len=85910000
    if x>3999992 and x<7000005: return 3999992 # for [3999992999993,7000005000007] len=3000012000014
    if x>7001003 and x<7001094: return 7001003 # for [7001003001007,7001094901007] len=91900000
    if x>7019990 and x<7020084: return 7019990 # for [7019990999107,7020084800207] len=93801100
    if x>7038972 and x<7039057: return 7038972 # for [7038972798307,7039057509307] len=84711000
    if x>7045928 and x<7046022: return 7045928 # for [7045928295407,7046022206407] len=93911000
    if x>7047012 and x<7047095: return 7047012 # for [7047012107407,7047095907407] len=83800000
    if x>7096130 and x<7096219: return 7096130 # for [7096130316907,7096219126907] len=88810000
    if x>7099578 and x<7099676: return 7099578 # for [7099578759907,7099676769907] len=98010000
    if x>7252502 and x<7252613: return 7252502 # for [7252502052527,7252613162527] len=111110000
    if x>7263061 and x<7263149: return 7263061 # for [7263061603627,7263149413627] len=87810000
    if x>7272878 and x<7272964: return 7272878 # for [7272878782727,7272964692727] len=85910000
    if x>7287387 and x<7287479: return 7287387 # for [7287387837827,7287479747827] len=91910000
    if x>7306892 and x<7306996: return 7306892 # for [7306892986037,7306996996037] len=104010000
    if x>7329552 and x<7329638: return 7329552 # for [7329552559237,7329638369237] len=85810000
    if x>7380915 and x<7381009: return 7380915 # for [7380915190837,7381009001837] len=93811000
    if x>7426371 and x<7426460: return 7426371 # for [7426371736247,7426460646247] len=88910000
    if x>7472247 and x<7472333: return 7472247 # for [7472247422747,7472333332747] len=85910000
    if x>7502150 and x<7502236: return 7502150 # for [7502150512057,7502236322057] len=85810000
    if x>7539539 and x<7539623: return 7539539 # for [7539539359357,7539623269357] len=83910000
    if x>7553420 and x<7553508: return 7553420 # for [7553420243557,7553508053557] len=87810000
    if x>7554169 and x<7554256: return 7554169 # for [7554169614557,7554256524557] len=86910000
    if x>7596822 and x<7596908: return 7596822 # for [7596822286957,7596908096957] len=85810000
    if x>7598977 and x<7599095: return 7598977 # for [7598977798957,7599095909957] len=118111000
    if x>7603718 and x<7603804: return 7603718 # for [7603718173067,7603804083067] len=85910000
    if x>7634405 and x<7634494: return 7634405 # for [7634405044367,7634494944367] len=89900000
    if x>7643015 and x<7643102: return 7643015 # for [7643015103467,7643102013467] len=86910000
    if x>7714674 and x<7714758: return 7714674 # for [7714674764177,7714758574177] len=83810000
    if x>7744499 and x<7744587: return 7744499 # for [7744499944477,7744587854477] len=87910000
    if x>7815061 and x<7815158: return 7815061 # for [7815061605187,7815158515187] len=96910000
    if x>7818318 and x<7818419: return 7818318 # for [7818318138187,7818419148187] len=101010000
    if x>7893225 and x<7893326: return 7893225 # for [7893225223987,7893326233987] len=101010000
    if x>7911324 and x<7911413: return 7911324 # for [7911324231197,7911413141197] len=88910000
    if x>7990371 and x<7990455: return 7990371 # for [7990371730997,7990455540997] len=83810000
    if x>7999992 and x<9000005: return 7999992 # for [7999992999997,9000005000009] len=1000012000012
    if x>9055968 and x<9056063: return 9055968 # for [9055968695509,9056063606509] len=94911000
    if x>9068952 and x<9069038: return 9068952 # for [9068952598609,9069038309609] len=85711000
    if x>9077584 and x<9077677: return 9077584 # for [9077584857709,9077677767709] len=92910000
    if x>9082892 and x<9082984: return 9082892 # for [9082892982809,9082984892809] len=91910000
    if x>9104206 and x<9104290: return 9104206 # for [9104206024019,9104290924019] len=84900000
    if x>9189091 and x<9189182: return 9189091 # for [9189091909819,9189182819819] len=90910000
    if x>9217970 and x<9218088: return 9217970 # for [9217970797129,9218088808129] len=118011000
    if x>9291891 and x<9291978: return 9291891 # for [9291891981929,9291978791929] len=86810000
    if x>9301158 and x<9301243: return 9301158 # for [9301158511039,9301243421039] len=84910000
    if x>9343898 and x<9343985: return 9343898 # for [9343898983439,9343985893439] len=86910000
    if x>9352254 and x<9352368: return 9352254 # for [9352254522539,9352368632539] len=114110000
    if x>9381629 and x<9381717: return 9381629 # for [9381629261839,9381717171839] len=87910000
    if x>9382782 and x<9382911: return 9382782 # for [9382782872839,9382911192839] len=128320000
    if x>9414706 and x<9414804: return 9414706 # for [9414706074149,9414804084149] len=98010000
    if x>9462147 and x<9462233: return 9462147 # for [9462147412649,9462233322649] len=85910000
    if x>9502466 and x<9502578: return 9502466 # for [9502466642059,9502578752059] len=112110000
    if x>9504203 and x<9504297: return 9504203 # for [9504203024059,9504297924059] len=94900000
    if x>9521129 and x<9521217: return 9521129 # for [9521129211259,9521217121259] len=87910000
    if x>9561550 and x<9561642: return 9561550 # for [9561550551659,9561642461659] len=91910000
    if x>9585315 and x<9585403: return 9585315 # for [9585315135859,9585403045859] len=87910000
    if x>9680260 and x<9680356: return 9680260 # for [9680260620869,9680356530869] len=95910000
    if x>9680690 and x<9680773: return 9680690 # for [9680690960869,9680773770869] len=82810000
    if x>9706147 and x<9706234: return 9706147 # for [9706147416079,9706234326079] len=86910000
    if x>9741239 and x<9741335: return 9741239 # for [9741239321479,9741335331479] len=96010000
    if x>9749101 and x<9749191: return 9749101 # for [9749101019479,9749191919479] len=90900000
    if x>9789768 and x<9789858: return 9789768 # for [9789768679879,9789858589879] len=89910000
    if x>9817766 and x<9817850: return 9817766 # for [9817766677189,9817850587189] len=83910000
    if x>9866762 and x<9866863: return 9866762 # for [9866762676689,9866863686689] len=101010000
    if x>9868480 and x<9868573: return 9868480 # for [9868480848689,9868573758689] len=92910000
    if x>9899025 and x<9899121: return 9899025 # for [9899025209989,9899121219989] len=96010000
    if x>9912130 and x<9912261: return 9912130 # for [9912130312199,9912261622199] len=131310000
    if x>9914907 and x<9914991: return 9914907 # for [9914907094199,9914991994199] len=84900000
    if x>9963023 and x<9963114: return 9963023 # for [9963023203699,9963114113699] len=90910000

    s = str(x)
    if x!=2 and s[0] in '2468':
        s = {'2':'1','4':'3','6':'5','8':'7'}[s[0]] + s[1:]
        return int(s)

    return x;

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

        tmp = skipGaps(self.count)
        if tmp != self.count:
            #print "skipped from %d to %d" % (self.count, tmp)
            self.count = tmp

            # recompute the limits
            log = len(str(self.count))
            self.pivot = True
            self.limitLo = 10**(log-1)
            self.limitHi = 10*self.limitLo - 1
        else:
            if self.count < self.limitLo:
                # less than 2 is invalid
                if self.count < 2:
                    raise StopIteration()

                if self.pivot:
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

#
# from:
# https://inventwithpython.com/rabinMiller.py
#
def rabinMiller(num):
    # Returns True if num is a prime number.

    s = num - 1
    t = 0
    while s % 2 == 0:
        # keep halving s while it is even (and use t
        # to count how many times we halve s)
        s = s // 2
        t += 1

    for trials in range(5): # try to falsify num's primality 5 times
        a = random.randrange(2, num - 1)
        v = pow(a, s, num)
        if v != 1: # this test does not apply if v is 1.
            i = 0
            while v != (num - 1):
                if i == t - 1:
                    return False
                else:
                    i = i + 1
                    v = (v ** 2) % num
    return True

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
    return rabinMiller(num)

#
# main
#
if __name__ == '__main__':
    if 0:
        n = int(raw_input())
    
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
    else:
        it = iter(PalindromeReverseIterator(9999999999999))
        #it = iter(PalindromeReverseIterator(9999999999))
        #it = iter(PalindromeReverseIterator(1000330001))
        for p in it:
            print p
    

