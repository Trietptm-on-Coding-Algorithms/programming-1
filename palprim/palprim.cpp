#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

typedef uint64_t u64;

/*****************************************************************************/
/* PALINDROME STUFF */
/*****************************************************************************/
u64 g_count;
u64 g_limit_lo;
u64 g_limit_hi;
bool g_pivot;

void palin_status()
{
    printf("   count: %" PRIu64 "\n", g_count);
    printf("limit_lo: %" PRIu64 "\n", g_limit_lo);
    printf("limit_hi: %" PRIu64 "\n", g_limit_hi);
    printf("   pivot: %d\n", g_pivot);
}

/* these intervals were made by enumerating the space of PP's in [0,10^13]
    they capture the even-digit skip optimization
    they capture the even leading digit optimization
    they capture the "is leading digit 5" optimization
    since they're the raw, top 128 gap intervals, they capture whatever optimizations
    I haven't thought of
*/
u64 palin_skip(u64 x)
{
    if(x>9989899ull and x<100030001ull) return 9989899ull; // interval_len=90040102
    if(x>199999991ull and x<300020003ull) return 199999991ull; // interval_len=100020012
    if(x>399878993ull and x<700020007ull) return 399878993ull; // interval_len=300141014
    if(x>799959997ull and x<900010009ull) return 799959997ull; // interval_len=100050012
    if(x>999727999ull and x<10000500001ull) return 999727999ull; // interval_len=9000772002
    if(x>19998289991ull and x<30000500003ull) return 19998289991ull; // interval_len=10002210012
    if(x>39998389993ull and x<70005450007ull) return 39998389993ull; // interval_len=30007060014
    if(x>79998589997ull and x<90000200009ull) return 79998589997ull; // interval_len=10001610012
    if(x>99999199999ull and x<1000008000001ull) return 99999199999ull; // interval_len=900008800002
    if(x>1021638361201ull and x<1021737371201ull) return 1021638361201ull; // interval_len=99010000
    if(x>1041465641401ull and x<1041550551401ull) return 1041465641401ull; // interval_len=84910000
    if(x>1055273725501ull and x<1055360635501ull) return 1055273725501ull; // interval_len=86910000
    if(x>1079554559701ull and x<1079647469701ull) return 1079554559701ull; // interval_len=92910000
    if(x>1114265624111ull and x<1114360634111ull) return 1114265624111ull; // interval_len=95010000
    if(x>1125572755211ull and x<1125656565211ull) return 1125572755211ull; // interval_len=83810000
    if(x>1134520254311ull and x<1134604064311ull) return 1134520254311ull; // interval_len=83810000
    if(x>1138614168311ull and x<1138712178311ull) return 1138614168311ull; // interval_len=98010000
    if(x>1182067602811ull and x<1182163612811ull) return 1182067602811ull; // interval_len=96010000
    if(x>1272727272721ull and x<1272815182721ull) return 1272727272721ull; // interval_len=87910000
    if(x>1316161616131ull and x<1316290926131ull) return 1316161616131ull; // interval_len=129310000
    if(x>1405161615041ull and x<1405253525041ull) return 1405161615041ull; // interval_len=91910000
    if(x>1436876786341ull and x<1436980896341ull) return 1436876786341ull; // interval_len=104110000
    if(x>1437594957341ull and x<1437681867341ull) return 1437594957341ull; // interval_len=86910000
    if(x>1507011107051ull and x<1507103017051ull) return 1507011107051ull; // interval_len=91910000
    if(x>1588279728851ull and x<1588369638851ull) return 1588279728851ull; // interval_len=89910000
    if(x>1614427244161ull and x<1614534354161ull) return 1614427244161ull; // interval_len=107110000
    if(x>1626654566261ull and x<1626747476261ull) return 1626654566261ull; // interval_len=92910000
    if(x>1730249420371ull and x<1730334330371ull) return 1730249420371ull; // interval_len=84910000
    if(x>1780990990871ull and x<1781090901871ull) return 1780990990871ull; // interval_len=99911000
    if(x>1821307031281ull and x<1821408041281ull) return 1821307031281ull; // interval_len=101010000
    if(x>1859959599581ull and x<1860083800681ull) return 1859959599581ull; // interval_len=124201100
    if(x>1878686868781ull and x<1878781878781ull) return 1878686868781ull; // interval_len=95010000
    if(x>1916320236191ull and x<1916410146191ull) return 1916320236191ull; // interval_len=89910000
    if(x>1964115114691ull and x<1964203024691ull) return 1964115114691ull; // interval_len=87910000
    if(x>1999987899991ull and x<3000002000003ull) return 1999987899991ull; // interval_len=1000014100012
    if(x>3025212125203ull and x<3025322235203ull) return 3025212125203ull; // interval_len=110110000
    if(x>3039218129303ull and x<3039308039303ull) return 3039218129303ull; // interval_len=89910000
    if(x>3122986892213ull and x<3123091903213ull) return 3122986892213ull; // interval_len=105011000
    if(x>3240488840423ull and x<3240582850423ull) return 3240488840423ull; // interval_len=94010000
    if(x>3245839385423ull and x<3245958595423ull) return 3245839385423ull; // interval_len=119210000
    if(x>3248241428423ull and x<3248325238423ull) return 3248241428423ull; // interval_len=83810000
    if(x>3259782879523ull and x<3259867689523ull) return 3259782879523ull; // interval_len=84810000
    if(x>3268679768623ull and x<3268764678623ull) return 3268679768623ull; // interval_len=84910000
    if(x>3293838383923ull and x<3293922293923ull) return 3293838383923ull; // interval_len=83910000
    if(x>3354236324533ull and x<3354324234533ull) return 3354236324533ull; // interval_len=87910000
    if(x>3361549451633ull and x<3361635361633ull) return 3361549451633ull; // interval_len=85910000
    if(x>3388371738833ull and x<3388459548833ull) return 3388371738833ull; // interval_len=87810000
    if(x>3444353534443ull and x<3444444444443ull) return 3444353534443ull; // interval_len=90910000
    if(x>3505005005053ull and x<3505092905053ull) return 3505005005053ull; // interval_len=87900000
    if(x>3512000002153ull and x<3512099902153ull) return 3512000002153ull; // interval_len=99900000
    if(x>3522152512253ull and x<3522239322253ull) return 3522152512253ull; // interval_len=86810000
    if(x>3550987890553ull and x<3551071701553ull) return 3550987890553ull; // interval_len=83811000
    if(x>3598644468953ull and x<3598729278953ull) return 3598644468953ull; // interval_len=84810000
    if(x>3626484846263ull and x<3626585856263ull) return 3626484846263ull; // interval_len=101010000
    if(x>3740459540473ull and x<3740570750473ull) return 3740459540473ull; // interval_len=111210000
    if(x>3750512150573ull and x<3750597950573ull) return 3750512150573ull; // interval_len=85800000
    if(x>3787903097873ull and x<3787995997873ull) return 3787903097873ull; // interval_len=92900000
    if(x>3875738375783ull and x<3875827285783ull) return 3875738375783ull; // interval_len=88910000
    if(x>3927162617293ull and x<3927275727293ull) return 3927162617293ull; // interval_len=113110000
    if(x>3942806082493ull and x<3942899982493ull) return 3942806082493ull; // interval_len=93900000
    if(x>3999627269993ull and x<3999713179993ull) return 3999627269993ull; // interval_len=85910000
    if(x>3999992999993ull and x<7000005000007ull) return 3999992999993ull; // interval_len=3000012000014
    if(x>7001003001007ull and x<7001094901007ull) return 7001003001007ull; // interval_len=91900000
    if(x>7019990999107ull and x<7020084800207ull) return 7019990999107ull; // interval_len=93801100
    if(x>7038972798307ull and x<7039057509307ull) return 7038972798307ull; // interval_len=84711000
    if(x>7045928295407ull and x<7046022206407ull) return 7045928295407ull; // interval_len=93911000
    if(x>7047012107407ull and x<7047095907407ull) return 7047012107407ull; // interval_len=83800000
    if(x>7096130316907ull and x<7096219126907ull) return 7096130316907ull; // interval_len=88810000
    if(x>7099578759907ull and x<7099676769907ull) return 7099578759907ull; // interval_len=98010000
    if(x>7252502052527ull and x<7252613162527ull) return 7252502052527ull; // interval_len=111110000
    if(x>7263061603627ull and x<7263149413627ull) return 7263061603627ull; // interval_len=87810000
    if(x>7272878782727ull and x<7272964692727ull) return 7272878782727ull; // interval_len=85910000
    if(x>7287387837827ull and x<7287479747827ull) return 7287387837827ull; // interval_len=91910000
    if(x>7306892986037ull and x<7306996996037ull) return 7306892986037ull; // interval_len=104010000
    if(x>7329552559237ull and x<7329638369237ull) return 7329552559237ull; // interval_len=85810000
    if(x>7380915190837ull and x<7381009001837ull) return 7380915190837ull; // interval_len=93811000
    if(x>7426371736247ull and x<7426460646247ull) return 7426371736247ull; // interval_len=88910000
    if(x>7472247422747ull and x<7472333332747ull) return 7472247422747ull; // interval_len=85910000
    if(x>7502150512057ull and x<7502236322057ull) return 7502150512057ull; // interval_len=85810000
    if(x>7539539359357ull and x<7539623269357ull) return 7539539359357ull; // interval_len=83910000
    if(x>7553420243557ull and x<7553508053557ull) return 7553420243557ull; // interval_len=87810000
    if(x>7554169614557ull and x<7554256524557ull) return 7554169614557ull; // interval_len=86910000
    if(x>7596822286957ull and x<7596908096957ull) return 7596822286957ull; // interval_len=85810000
    if(x>7598977798957ull and x<7599095909957ull) return 7598977798957ull; // interval_len=118111000
    if(x>7603718173067ull and x<7603804083067ull) return 7603718173067ull; // interval_len=85910000
    if(x>7634405044367ull and x<7634494944367ull) return 7634405044367ull; // interval_len=89900000
    if(x>7643015103467ull and x<7643102013467ull) return 7643015103467ull; // interval_len=86910000
    if(x>7714674764177ull and x<7714758574177ull) return 7714674764177ull; // interval_len=83810000
    if(x>7744499944477ull and x<7744587854477ull) return 7744499944477ull; // interval_len=87910000
    if(x>7815061605187ull and x<7815158515187ull) return 7815061605187ull; // interval_len=96910000
    if(x>7818318138187ull and x<7818419148187ull) return 7818318138187ull; // interval_len=101010000
    if(x>7893225223987ull and x<7893326233987ull) return 7893225223987ull; // interval_len=101010000
    if(x>7911324231197ull and x<7911413141197ull) return 7911324231197ull; // interval_len=88910000
    if(x>7990371730997ull and x<7990455540997ull) return 7990371730997ull; // interval_len=83810000
    if(x>7999992999997ull and x<9000005000009ull) return 7999992999997ull; // interval_len=1000012000012
    if(x>9055968695509ull and x<9056063606509ull) return 9055968695509ull; // interval_len=94911000
    if(x>9068952598609ull and x<9069038309609ull) return 9068952598609ull; // interval_len=85711000
    if(x>9077584857709ull and x<9077677767709ull) return 9077584857709ull; // interval_len=92910000
    if(x>9082892982809ull and x<9082984892809ull) return 9082892982809ull; // interval_len=91910000
    if(x>9104206024019ull and x<9104290924019ull) return 9104206024019ull; // interval_len=84900000
    if(x>9189091909819ull and x<9189182819819ull) return 9189091909819ull; // interval_len=90910000
    if(x>9217970797129ull and x<9218088808129ull) return 9217970797129ull; // interval_len=118011000
    if(x>9291891981929ull and x<9291978791929ull) return 9291891981929ull; // interval_len=86810000
    if(x>9301158511039ull and x<9301243421039ull) return 9301158511039ull; // interval_len=84910000
    if(x>9343898983439ull and x<9343985893439ull) return 9343898983439ull; // interval_len=86910000
    if(x>9352254522539ull and x<9352368632539ull) return 9352254522539ull; // interval_len=114110000
    if(x>9381629261839ull and x<9381717171839ull) return 9381629261839ull; // interval_len=87910000
    if(x>9382782872839ull and x<9382911192839ull) return 9382782872839ull; // interval_len=128320000
    if(x>9414706074149ull and x<9414804084149ull) return 9414706074149ull; // interval_len=98010000
    if(x>9462147412649ull and x<9462233322649ull) return 9462147412649ull; // interval_len=85910000
    if(x>9502466642059ull and x<9502578752059ull) return 9502466642059ull; // interval_len=112110000
    if(x>9504203024059ull and x<9504297924059ull) return 9504203024059ull; // interval_len=94900000
    if(x>9521129211259ull and x<9521217121259ull) return 9521129211259ull; // interval_len=87910000
    if(x>9561550551659ull and x<9561642461659ull) return 9561550551659ull; // interval_len=91910000
    if(x>9585315135859ull and x<9585403045859ull) return 9585315135859ull; // interval_len=87910000
    if(x>9680260620869ull and x<9680356530869ull) return 9680260620869ull; // interval_len=95910000
    if(x>9680690960869ull and x<9680773770869ull) return 9680690960869ull; // interval_len=82810000
    if(x>9706147416079ull and x<9706234326079ull) return 9706147416079ull; // interval_len=86910000
    if(x>9741239321479ull and x<9741335331479ull) return 9741239321479ull; // interval_len=96010000
    if(x>9749101019479ull and x<9749191919479ull) return 9749101019479ull; // interval_len=90900000
    if(x>9789768679879ull and x<9789858589879ull) return 9789768679879ull; // interval_len=89910000
    if(x>9817766677189ull and x<9817850587189ull) return 9817766677189ull; // interval_len=83910000
    if(x>9866762676689ull and x<9866863686689ull) return 9866762676689ull; // interval_len=101010000
    if(x>9868480848689ull and x<9868573758689ull) return 9868480848689ull; // interval_len=92910000
    if(x>9899025209989ull and x<9899121219989ull) return 9899025209989ull; // interval_len=96010000
    if(x>9912130312199ull and x<9912261622199ull) return 9912130312199ull; // interval_len=131310000
    if(x>9914907094199ull and x<9914991994199ull) return 9914907094199ull; // interval_len=84900000
    if(x>9963023203699ull and x<9963114113699ull) return 9963023203699ull; // interval_len=90910000
    return x;
}

/* map number of digits in count to low and hi limits */
u64 lookup_limit_lo[8] = { -1, 2, 10, 100, 1000, 10000, 100000, 1000000 };
u64 lookup_limit_hi[8] = { -1, 9, 99, 999, 9999, 99999, 999999, 9999999 };

bool palin_test(u64 n)
{
    char buf[16];
    int n_digits = sprintf(buf, "%" PRIu64, n);
    for(int i=0; i<n_digits/2; ++i)
        if(buf[i] != buf[n_digits-i-1])
            return false;
    return true;
}

void palin_init(u64 n)
{
    char buf[16];
    int n_digits = sprintf(buf, "%" PRIu64, n);
    if(n_digits % 2) {
        /* odd digits */
        n_digits = n_digits/2+1;
        buf[n_digits] = '\0';
        g_count = strtoul(buf, NULL, 10);
        g_pivot = true;
    }
    else {
        /* even number of digits */
        n_digits /= 2;
        buf[n_digits] = '\0';
        g_count = strtoul(buf, NULL, 10);
        g_pivot = false;
    }

    g_limit_lo = lookup_limit_lo[n_digits];
    g_limit_hi = lookup_limit_hi[n_digits];

    /* if it's already a palindrome, bias for the next() call */
    if(palin_test(g_count))
        g_count += 1;

    //palin_status();
}

u64 palin_next()
{
    //printf("palin_next() here with g_count=%" PRIu64 ", g_limit_lo=%" PRIu64 " pivot=%d\n", g_count, g_limit_lo, g_pivot);
    g_count -= 1;
    char buf[16];
    int n = -1;

    if(g_count < g_limit_lo) {
        n = sprintf(buf, "%" PRIu64, g_count);

        if(g_pivot) {
            if(g_count < 2)
                return -1;

            g_pivot = false;
            g_limit_lo = lookup_limit_lo[n];
            g_limit_hi = lookup_limit_hi[n];
            /* count reset with new limit, width */
            g_count = g_limit_hi;
        } else {
            g_pivot = true;
            /* count reset */
            g_count = g_limit_hi;
        }
            
        n = sprintf(buf, "%" PRIu64, g_count);

        //palin_status();
    }


    //printf("forming answer with g_count=%" PRIu64 ", pivot=%d\n", g_count, g_pivot);

    /* form answer */
    if(n < 0) 
        n = sprintf(buf, "%" PRIu64, g_count);

    if(g_pivot) {
        //printf("forming answer w/ pivot (n=%d)\n", n);
        //palin_status();
        for(int i=0; i<n-1; ++i)
            buf[2*n-2-i] = buf[i];
        buf[2*n-1] = '\0';
    } 
    else {
        //printf("forming answer w/o pivot (n=%d)\n", n);
        for(int i=0; i<n; ++i) 
            buf[2*n-1-i] = buf[i];
        buf[2*n] = '\0';
    }
    //printf("done! buf is: -%s-\n", buf);
    return strtoul(buf, NULL, 10);
}

/*****************************************************************************/
/* PRIMALITY TESTING */
/*****************************************************************************/

u64 sqrmod(u64 base, u64 mod)
{
    if(!(base & 0xFFFFFFFF00000000ull)) {
        return (base * base) % mod;
    }

    u64 a = base >> 32;
    u64 b = base & 0xFFFFFFFF;

    // b^2 (mod n)
    u64 t0 = b*b % mod;
    // 2*ab*(2^32)
    u64 t1 = a*b % mod;
    t1 = (t1 << 17) % mod;
    t1 = (t1 << 16) % mod;
    // a^2 * 2^32 * 2^32
    u64 t2 = a*a % mod;
    t2 = (t2 << 16) % mod;
    t2 = (t2 << 16) % mod;
    t2 = (t2 << 16) % mod;
    t2 = (t2 << 16) % mod;

    // the final
    return (t0+t1+t2) % mod;
}

// modulus in this challenge can be at most 10^13 (44 bits) so each remainder
// calculated can be that big - we're able to shift at most 20 at a time then
// in 64-bit register without overflow
u64 mulmod(u64 factor0, u64 factor1, u64 mod)
{
    if(!(factor0 & 0xFFFFFFFF00000000ull) && !(factor1 & 0xFFFFFFFF00000000ull)) {
        return (factor0 * factor1) % mod;
    }

    u64 a = factor0 >> 32;
    u64 b = factor0 & 0xFFFFFFFF;
    u64 c = factor1 >> 32;
    u64 d = factor1 & 0xFFFFFFFF;

    //   a b
    // x c d
    // -----
    //     bd
    //   da
    //   cb
    // ca

    // 
    u64 t0 = d*b % mod;
    // 
    u64 t1 = d*a % mod;
    u64 t2 = c*b % mod;
    u64 t3 = (t1 + t2) % mod;
    t3 = (t3 << 16) % mod;
    t3 = (t3 << 16) % mod;
    // 
    u64 t4 = c*a % mod;
    t4 = (t4 << 16) % mod;
    t4 = (t4 << 16) % mod;
    t4 = (t4 << 16) % mod;
    t4 = (t4 << 16) % mod;

    // the final
    return (t0+t3+t4) % mod;
}

// calculate a^n%mod
u64 powmod(u64 a, u64 n, u64 mod)
{
    //printf("powmod(a=%" PRIu64 ", n=%" PRIu64 ", mod=%" PRIu64 ")\n", a, n, mod);
    u64 runner = a;
    u64 result = 1;
 
    while (n)
    {
        if (n & 1) {
            result = mulmod(result, runner, mod);
            //printf("new result=%" PRIu64 "\n", result);
        }
        //printf("computing %" PRIu64 " ^2 mod  %" PRIu64 " \n", runner, n);
        runner = sqrmod(runner, mod);
        //printf("new runner=%" PRIu64 "\n", runner);
        n >>= 1;
    }
    //printf("computed result=%" PRIu64 "\n", result);
    return result;
}
 
// n−1 = 2^s * d with d odd by factoring powers of 2 from n−1
bool witness(u64 n, u64 s, u64 d, u64 a)
{
    //printf("witness(n=%" PRIu64 ", s=%" PRIu64 ", d=%" PRIu64 ", a=%" PRIu64 ")\n", n, s, d, a);

    // if prime -> search_satisfied
    //
    // where search_satisfied is defined as finding a,d,r:
    //   a^d=1(mod n) or 
    //   a^(2^r*d)=-1(mod n) for r < s, r possibly 0
    //
    // converse it not true:
    //   if search_satisfied, primality is not guaranteed (liar case)
    //
    // contrapositive: if not search_satisfied -> not prime (witness compositeness)

    u64 x = powmod(a, d, n); // a^d
    if(x == 1 || x==(n-1)) {
        //printf("found a^d=1 (mod n) so we cannot testify to compositeness\n");
        /* search satisfied, we do NOT witness compositeness */
        return false;
    }
       
    // try all a^(2*d), a^(2^2*d), a^(2^3*d), ..., a^(2^s*d)
    for(int i=1; i<=s; ++i) {
        // compute a^(2^1*d), a^(2^2*d), ...
        x = sqrmod(x, n);
        //printf("a^(2^%d*d)=%" PRIu64 " (mod n)\n", i, x);

        if(x == (n-1)) { // note n-1 = -1 (mod n)
            //printf("found a^(2^%d*d)=-1 (mod n) so we cannot testify to compositeness\n", i);
            return false;
        }
    }

    //printf("search satisfied is false, so this is not prime (witness compositeness)\n");
    return true;
}
 
/*
from https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test:

For example, Pomerance, Selfridge and Wagstaff[8] and Jaeschke[9] have verified that
if n < 2,047, it is enough to test a = 2;
if n < 1,373,653, it is enough to test a = 2 and 3;
if n < 9,080,191, it is enough to test a = 31 and 73;
if n < 25,326,001, it is enough to test a = 2, 3, and 5;
if n < 3,215,031,751, it is enough to test a = 2, 3, 5, and 7;
if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;
if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;
if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;
if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.
*/

bool is_prime_mr(u64 n)
{
    if(n==2) return true;

    /* even numbers other than 2 are composite */
    if(!(n&1)) return false;

    /* factor power's of 2 from n-1 */
    u64 d = (n-1) / 2;
    u64 s = 1;
    while (!(d & 1)) {
        d >>= 1;
        ++s;
    }

    //printf("d=%" PRIu64 "\n", d);
    //printf("s=%" PRIu64 "\n", s);

    /* two witness case */
    if(n < 9080191ull)
        return !witness(n,s,d,31) && !witness(n,s,d,73);
    /* three witness case */
    if(n < 4759123141ull)
        return !witness(n,s,d,2) && !witness(n,s,d,7) && !witness(n,s,d,61);
    /* four witness case */
    if(n < 1122004669633ull)
        return !witness(n,s,d,2) && !witness(n,s,d,13) && !witness(n,s,d,23) && !witness(n,s,d,1662803);
    /* 5 */
    if(n < 2152302898747ull)
        return !witness(n,s,d,2) && !witness(n,s,d,3) && !witness(n,s,d,5) && !witness(n,s,d,7) && !witness(n,s,d,11);
    /* 6 */
    if(n < 3474749660383ull)
        return !witness(n,s,d,2) && !witness(n,s,d,3) && !witness(n,s,d,5) && !witness(n,s,d,7) && !witness(n,s,d,11) && !witness(n,s,d,13);
    /* 7 */
    return !witness(n,s,d,2) && !witness(n,s,d,3) && !witness(n,s,d,5) && !witness(n,s,d,7) && !witness(n,s,d,11) && !witness(n,s,d,13) && !witness(n,s,d,17);
}

bool is_prime(u64 n)
{
    // 0, 1, negative are not prime 
    if(n < 2) return false;

    // even numbers other than 2 are not prime
    if(n == 2) return true;
    if(!(n&1)) return false;

    // 168 primes below 1000:
    u64 small_primes[167] = { /*2,*/ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

    // 
    for(int i=0; i<167; ++i)
        if(n % small_primes[i] == 0)
            return false;

    return is_prime_mr(n);
}

/*****************************************************************************/
/* MAIN */
/*****************************************************************************/

int main()
{
    //printf("%d\n", is_prime_mr(91821712819));
    //return 0;

    if(1) {
        int num_cases;

        /*
        clock_t begin, delta, max=0;
        */

        scanf("%d", &num_cases);
        for(int i=0; i<num_cases; ++i) {
            u64 start;
            scanf("%" PRIu64, &start);
            //printf("working on %" PRIu64 "...", start);

            //begin = clock();

            printf("attempt lookup on %" PRIu64 "\n", start);
            u64 tmp = palin_skip(start);
            if(tmp != start) {
                printf("a hit!\n");
                printf("%" PRIu64 "\n", tmp);
            }
            else {
                palin_init(start);

                while(1) {
                    u64 p = palin_next();
                    //printf("trying: %" PRIu64 "\n", p);
                    if(is_prime_mr(p)) {
                        printf("%" PRIu64 "\n", p);
                        break;
                    }
                }
            }

            /* timer junk */
            /*
            delta = clock() - begin;
            if(delta > max) {
                printf("NEW RECORD: took %" PRIu64 "\n", delta);
                max = delta;
            }
            */
        }
    }
    else {
        palin_init(9999999999999ull);

        while(1) {
            u64 p = palin_next();

            if(p == -1) break;
   
            if(is_prime_mr(p))
                printf("%" PRIu64 "\n", p);

        }
    }

    return 0;
}
