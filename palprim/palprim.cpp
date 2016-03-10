#include <stdio.h>
#include <stdlib.h>

typedef unsigned long int u64;
typedef __uint128_t bn; // bignum

/*****************************************************************************/
/* PRIME PALINDROME STUFF */
/*****************************************************************************/
u64 g_count;
u64 g_limit_lo;
u64 g_limit_hi;
bool g_pivot;

void palin_status()
{
    printf("   count: %lu\n", g_count);
    printf("limit_lo: %lu\n", g_limit_lo);
    printf("limit_hi: %lu\n", g_limit_hi);
    printf("   pivot: %d\n", g_pivot);
}

u64 palin_skip(u64 x)
{
    if(x>9989 and x<10003) return 9989; // for [9989899,100030001] len=90040102
    if(x>19999 and x<30002) return 19999; // for [199999991,300020003] len=100020012
    if(x>39987 and x<70002) return 39987; // for [399878993,700020007] len=300141014
    if(x>79995 and x<90001) return 79995; // for [799959997,900010009] len=100050012
    if(x>99972 and x<100005) return 99972; // for [999727999,10000500001] len=9000772002
    if(x>199982 and x<300005) return 199982; // for [19998289991,30000500003] len=10002210012
    if(x>399983 and x<700054) return 399983; // for [39998389993,70005450007] len=30007060014
    if(x>799985 and x<900002) return 799985; // for [79998589997,90000200009] len=10001610012
    if(x>999991 and x<1000008) return 999991; // for [99999199999,1000008000001] len=900008800002
    if(x>1021638 and x<1021737) return 1021638; // for [1021638361201,1021737371201] len=99010000
    if(x>1041465 and x<1041550) return 1041465; // for [1041465641401,1041550551401] len=84910000
    if(x>1055273 and x<1055360) return 1055273; // for [1055273725501,1055360635501] len=86910000
    if(x>1079554 and x<1079647) return 1079554; // for [1079554559701,1079647469701] len=92910000
    if(x>1114265 and x<1114360) return 1114265; // for [1114265624111,1114360634111] len=95010000
    if(x>1125572 and x<1125656) return 1125572; // for [1125572755211,1125656565211] len=83810000
    if(x>1134520 and x<1134604) return 1134520; // for [1134520254311,1134604064311] len=83810000
    if(x>1138614 and x<1138712) return 1138614; // for [1138614168311,1138712178311] len=98010000
    if(x>1182067 and x<1182163) return 1182067; // for [1182067602811,1182163612811] len=96010000
    if(x>1272727 and x<1272815) return 1272727; // for [1272727272721,1272815182721] len=87910000
    if(x>1316161 and x<1316290) return 1316161; // for [1316161616131,1316290926131] len=129310000
    if(x>1405161 and x<1405253) return 1405161; // for [1405161615041,1405253525041] len=91910000
    if(x>1436876 and x<1436980) return 1436876; // for [1436876786341,1436980896341] len=104110000
    if(x>1437594 and x<1437681) return 1437594; // for [1437594957341,1437681867341] len=86910000
    if(x>1507011 and x<1507103) return 1507011; // for [1507011107051,1507103017051] len=91910000
    if(x>1588279 and x<1588369) return 1588279; // for [1588279728851,1588369638851] len=89910000
    if(x>1614427 and x<1614534) return 1614427; // for [1614427244161,1614534354161] len=107110000
    if(x>1626654 and x<1626747) return 1626654; // for [1626654566261,1626747476261] len=92910000
    if(x>1730249 and x<1730334) return 1730249; // for [1730249420371,1730334330371] len=84910000
    if(x>1780990 and x<1781090) return 1780990; // for [1780990990871,1781090901871] len=99911000
    if(x>1821307 and x<1821408) return 1821307; // for [1821307031281,1821408041281] len=101010000
    if(x>1859959 and x<1860083) return 1859959; // for [1859959599581,1860083800681] len=124201100
    if(x>1878686 and x<1878781) return 1878686; // for [1878686868781,1878781878781] len=95010000
    if(x>1916320 and x<1916410) return 1916320; // for [1916320236191,1916410146191] len=89910000
    if(x>1964115 and x<1964203) return 1964115; // for [1964115114691,1964203024691] len=87910000
    if(x>1999987 and x<3000002) return 1999987; // for [1999987899991,3000002000003] len=1000014100012
    if(x>3025212 and x<3025322) return 3025212; // for [3025212125203,3025322235203] len=110110000
    if(x>3039218 and x<3039308) return 3039218; // for [3039218129303,3039308039303] len=89910000
    if(x>3122986 and x<3123091) return 3122986; // for [3122986892213,3123091903213] len=105011000
    if(x>3240488 and x<3240582) return 3240488; // for [3240488840423,3240582850423] len=94010000
    if(x>3245839 and x<3245958) return 3245839; // for [3245839385423,3245958595423] len=119210000
    if(x>3248241 and x<3248325) return 3248241; // for [3248241428423,3248325238423] len=83810000
    if(x>3259782 and x<3259867) return 3259782; // for [3259782879523,3259867689523] len=84810000
    if(x>3268679 and x<3268764) return 3268679; // for [3268679768623,3268764678623] len=84910000
    if(x>3293838 and x<3293922) return 3293838; // for [3293838383923,3293922293923] len=83910000
    if(x>3354236 and x<3354324) return 3354236; // for [3354236324533,3354324234533] len=87910000
    if(x>3361549 and x<3361635) return 3361549; // for [3361549451633,3361635361633] len=85910000
    if(x>3388371 and x<3388459) return 3388371; // for [3388371738833,3388459548833] len=87810000
    if(x>3444353 and x<3444444) return 3444353; // for [3444353534443,3444444444443] len=90910000
    if(x>3505005 and x<3505092) return 3505005; // for [3505005005053,3505092905053] len=87900000
    if(x>3512000 and x<3512099) return 3512000; // for [3512000002153,3512099902153] len=99900000
    if(x>3522152 and x<3522239) return 3522152; // for [3522152512253,3522239322253] len=86810000
    if(x>3550987 and x<3551071) return 3550987; // for [3550987890553,3551071701553] len=83811000
    if(x>3598644 and x<3598729) return 3598644; // for [3598644468953,3598729278953] len=84810000
    if(x>3626484 and x<3626585) return 3626484; // for [3626484846263,3626585856263] len=101010000
    if(x>3740459 and x<3740570) return 3740459; // for [3740459540473,3740570750473] len=111210000
    if(x>3750512 and x<3750597) return 3750512; // for [3750512150573,3750597950573] len=85800000
    if(x>3787903 and x<3787995) return 3787903; // for [3787903097873,3787995997873] len=92900000
    if(x>3875738 and x<3875827) return 3875738; // for [3875738375783,3875827285783] len=88910000
    if(x>3927162 and x<3927275) return 3927162; // for [3927162617293,3927275727293] len=113110000
    if(x>3942806 and x<3942899) return 3942806; // for [3942806082493,3942899982493] len=93900000
    if(x>3999627 and x<3999713) return 3999627; // for [3999627269993,3999713179993] len=85910000
    if(x>3999992 and x<7000005) return 3999992; // for [3999992999993,7000005000007] len=3000012000014
    if(x>7001003 and x<7001094) return 7001003; // for [7001003001007,7001094901007] len=91900000
    if(x>7019990 and x<7020084) return 7019990; // for [7019990999107,7020084800207] len=93801100
    if(x>7038972 and x<7039057) return 7038972; // for [7038972798307,7039057509307] len=84711000
    if(x>7045928 and x<7046022) return 7045928; // for [7045928295407,7046022206407] len=93911000
    if(x>7047012 and x<7047095) return 7047012; // for [7047012107407,7047095907407] len=83800000
    if(x>7096130 and x<7096219) return 7096130; // for [7096130316907,7096219126907] len=88810000
    if(x>7099578 and x<7099676) return 7099578; // for [7099578759907,7099676769907] len=98010000
    if(x>7252502 and x<7252613) return 7252502; // for [7252502052527,7252613162527] len=111110000
    if(x>7263061 and x<7263149) return 7263061; // for [7263061603627,7263149413627] len=87810000
    if(x>7272878 and x<7272964) return 7272878; // for [7272878782727,7272964692727] len=85910000
    if(x>7287387 and x<7287479) return 7287387; // for [7287387837827,7287479747827] len=91910000
    if(x>7306892 and x<7306996) return 7306892; // for [7306892986037,7306996996037] len=104010000
    if(x>7329552 and x<7329638) return 7329552; // for [7329552559237,7329638369237] len=85810000
    if(x>7380915 and x<7381009) return 7380915; // for [7380915190837,7381009001837] len=93811000
    if(x>7426371 and x<7426460) return 7426371; // for [7426371736247,7426460646247] len=88910000
    if(x>7472247 and x<7472333) return 7472247; // for [7472247422747,7472333332747] len=85910000
    if(x>7502150 and x<7502236) return 7502150; // for [7502150512057,7502236322057] len=85810000
    if(x>7539539 and x<7539623) return 7539539; // for [7539539359357,7539623269357] len=83910000
    if(x>7553420 and x<7553508) return 7553420; // for [7553420243557,7553508053557] len=87810000
    if(x>7554169 and x<7554256) return 7554169; // for [7554169614557,7554256524557] len=86910000
    if(x>7596822 and x<7596908) return 7596822; // for [7596822286957,7596908096957] len=85810000
    if(x>7598977 and x<7599095) return 7598977; // for [7598977798957,7599095909957] len=118111000
    if(x>7603718 and x<7603804) return 7603718; // for [7603718173067,7603804083067] len=85910000
    if(x>7634405 and x<7634494) return 7634405; // for [7634405044367,7634494944367] len=89900000
    if(x>7643015 and x<7643102) return 7643015; // for [7643015103467,7643102013467] len=86910000
    if(x>7714674 and x<7714758) return 7714674; // for [7714674764177,7714758574177] len=83810000
    if(x>7744499 and x<7744587) return 7744499; // for [7744499944477,7744587854477] len=87910000
    if(x>7815061 and x<7815158) return 7815061; // for [7815061605187,7815158515187] len=96910000
    if(x>7818318 and x<7818419) return 7818318; // for [7818318138187,7818419148187] len=101010000
    if(x>7893225 and x<7893326) return 7893225; // for [7893225223987,7893326233987] len=101010000
    if(x>7911324 and x<7911413) return 7911324; // for [7911324231197,7911413141197] len=88910000
    if(x>7990371 and x<7990455) return 7990371; // for [7990371730997,7990455540997] len=83810000
    if(x>7999992 and x<9000005) return 7999992; // for [7999992999997,9000005000009] len=1000012000012
    if(x>9055968 and x<9056063) return 9055968; // for [9055968695509,9056063606509] len=94911000
    if(x>9068952 and x<9069038) return 9068952; // for [9068952598609,9069038309609] len=85711000
    if(x>9077584 and x<9077677) return 9077584; // for [9077584857709,9077677767709] len=92910000
    if(x>9082892 and x<9082984) return 9082892; // for [9082892982809,9082984892809] len=91910000
    if(x>9104206 and x<9104290) return 9104206; // for [9104206024019,9104290924019] len=84900000
    if(x>9189091 and x<9189182) return 9189091; // for [9189091909819,9189182819819] len=90910000
    if(x>9217970 and x<9218088) return 9217970; // for [9217970797129,9218088808129] len=118011000
    if(x>9291891 and x<9291978) return 9291891; // for [9291891981929,9291978791929] len=86810000
    if(x>9301158 and x<9301243) return 9301158; // for [9301158511039,9301243421039] len=84910000
    if(x>9343898 and x<9343985) return 9343898; // for [9343898983439,9343985893439] len=86910000
    if(x>9352254 and x<9352368) return 9352254; // for [9352254522539,9352368632539] len=114110000
    if(x>9381629 and x<9381717) return 9381629; // for [9381629261839,9381717171839] len=87910000
    if(x>9382782 and x<9382911) return 9382782; // for [9382782872839,9382911192839] len=128320000
    if(x>9414706 and x<9414804) return 9414706; // for [9414706074149,9414804084149] len=98010000
    if(x>9462147 and x<9462233) return 9462147; // for [9462147412649,9462233322649] len=85910000
    if(x>9502466 and x<9502578) return 9502466; // for [9502466642059,9502578752059] len=112110000
    if(x>9504203 and x<9504297) return 9504203; // for [9504203024059,9504297924059] len=94900000
    if(x>9521129 and x<9521217) return 9521129; // for [9521129211259,9521217121259] len=87910000
    if(x>9561550 and x<9561642) return 9561550; // for [9561550551659,9561642461659] len=91910000
    if(x>9585315 and x<9585403) return 9585315; // for [9585315135859,9585403045859] len=87910000
    if(x>9680260 and x<9680356) return 9680260; // for [9680260620869,9680356530869] len=95910000
    if(x>9680690 and x<9680773) return 9680690; // for [9680690960869,9680773770869] len=82810000
    if(x>9706147 and x<9706234) return 9706147; // for [9706147416079,9706234326079] len=86910000
    if(x>9741239 and x<9741335) return 9741239; // for [9741239321479,9741335331479] len=96010000
    if(x>9749101 and x<9749191) return 9749101; // for [9749101019479,9749191919479] len=90900000
    if(x>9789768 and x<9789858) return 9789768; // for [9789768679879,9789858589879] len=89910000
    if(x>9817766 and x<9817850) return 9817766; // for [9817766677189,9817850587189] len=83910000
    if(x>9866762 and x<9866863) return 9866762; // for [9866762676689,9866863686689] len=101010000
    if(x>9868480 and x<9868573) return 9868480; // for [9868480848689,9868573758689] len=92910000
    if(x>9899025 and x<9899121) return 9899025; // for [9899025209989,9899121219989] len=96010000
    if(x>9912130 and x<9912261) return 9912130; // for [9912130312199,9912261622199] len=131310000
    if(x>9914907 and x<9914991) return 9914907; // for [9914907094199,9914991994199] len=84900000
    if(x>9963023 and x<9963114) return 9963023; // for [9963023203699,9963114113699] len=90910000
 
/*
    // no even digits up front
    if(x != 2) {
        char buf[16];
        sprintf(buf, "%lu", x);
        if(buf[0] == '2' || buf[0] == '4' || buf[0] == '6' || buf[0]==8) {
            buf[0]--;
            x = strtoul(buf, NULL, 10);
        }
    }
*/

    return x;
}

/* map number of digits in count to low and hi limits */
u64 lookup_limit_lo[8] = { -1, 2, 10, 100, 1000, 10000, 100000, 1000000 };
u64 lookup_limit_hi[8] = { -1, 9, 99, 999, 9999, 99999, 999999, 9999999 };

bool palin_test(u64 n)
{
    char buf[16];
    int n_digits = sprintf(buf, "%lu", n);
    for(int i=0; i<n_digits/2; ++i)
        if(buf[i] != buf[n_digits-i-1])
            return false;
    return true;
}

void palin_init(u64 n)
{
    char buf[16];
    int n_digits = sprintf(buf, "%lu", n);
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
    //printf("palin_next() here with g_count=%lu, g_limit_lo=%lu pivot=%d\n", g_count, g_limit_lo, g_pivot);
    g_count -= 1;
    char buf[16];
    int n = -1;
    u64 tmp = palin_skip(g_count);
    if(tmp != g_count) {
        //printf("skipped from %lu to %lu\n", g_count, tmp);
        g_count = tmp;

        /* count reset with new limit, width */
        n = sprintf(buf, "%lu", g_count);
        g_pivot = true;
        g_limit_lo = lookup_limit_lo[n];
        g_limit_hi = lookup_limit_hi[n];
    }
    else if(g_count < g_limit_lo) {
        n = sprintf(buf, "%lu", g_count);

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
            
        n = sprintf(buf, "%lu", g_count);

        //palin_status();
    }


    //printf("forming answer with g_count=%lu, pivot=%d\n", g_count, g_pivot);

    /* form answer */
    if(n < 0) 
        n = sprintf(buf, "%lu", g_count);

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

// from https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test#Deterministic_up_to_341.2C550.2C071.2C728.2C321
// claim: Deterministic up to 341,550,071,728,321[edit]

// calcul a^n%mod
u64 expmod(u64 a, u64 n, u64 mod)
{
    //printf("expmod(a=%lu, n=%lu, mod=%lu)\n", a, n, mod);
    u64 runner = a;
    u64 result = 1;
 
    while (n)
    {
        if (n & 1) {
            result = ((bn)result * runner) % mod;
            //printf("%lx:%lx\n", (u64)(tmp>>64), (u64)(tmp & 0xFFFFFFFFFFFFFFFF));
            //printf("new result=%lu\n", result);
        }
        runner = ((bn)runner * runner) % mod;
        //printf("new runner=%lu\n", runner);
        n >>= 1;
    }
    //printf("computed result=%lu\n", result);
    return result;
}
 
// n−1 = 2^s * d with d odd by factoring powers of 2 from n−1
bool witness(u64 n, u64 s, u64 d, u64 a)
{
    //printf("witness(n=%lu, s=%lu, d=%lu, a=%lu)\n", n, s, d, a);
    // if prime, a^d=1(mod n)
    //       and a^(2^r*d)=-1(mod n) (where r < s)
    //
    // to witness compositeness, we need to show that a^d and a^(2^r*d) does not
    // equal 1 or -1

    u64 x = expmod(a, d, n); // a^d
    u64 y;
 
    for(; s; s--) {
        // compute a^(2^1*d), a^(2^2*d), ...
        y = ((bn)x * x) % n;

        if (y == 1 && x != 1 && x != n-1)
            return false;

        x = y;
    }
    if (y != 1)
        return false;

    return true;
}
 
/*
 * if n < 1,373,653, it is enough to test a = 2 and 3;
 * if n < 9,080,191, it is enough to test a = 31 and 73;
 * if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
 * if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;
 * if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;
 * if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;
 * if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.
 */
 
bool is_prime_mr(u64 n)
{
    if ( (!(n & 1) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3))
        return false;
    if (n <= 3)
        return true;

    u64 d = (n-1) / 2;
    u64 s = 1;
    while (!(d & 1)) {
        d >>= 1;
        ++s;
    }

    //printf("d=%lu\n", d);
    //printf("s=%lu\n", s);
 
    if (n < 1373653)
        return witness(n,s,d,2) && witness(n,s,d,3);
    if (n < 9080191)
        return witness(n,s,d,31) && witness(n,s,d,73);
    if (n < 4759123141)
        return witness(n,s,d,2) && witness(n,s,d,7) && witness(n,s,d,61);
    if (n < 1122004669633)
        return witness(n,s,d,2) && witness(n,s,d,13) && witness(n,s,d,23) && witness(n,s,d,1662803);
    if (n < 2152302898747)
        return witness(n,s,d,2) && witness(n,s,d,3) && witness(n,s,d,5) && witness(n,s,d,7) && witness(n,s,d,11);
    if (n < 3474749660383)
        return witness(n,s,d,2) && witness(n,s,d,3) && witness(n,s,d,5) && witness(n,s,d,7) && witness(n,s,d,11) && witness(n,s,d,13);
    return witness(n,s,d,2) && witness(n,s,d,3) && witness(n,s,d,5) && witness(n,s,d,7) && witness(n,s,d,11) && witness(n,s,d,13) && witness(n,s,d,17);
}

/*****************************************************************************/
/* MAIN */
/*****************************************************************************/

int main()
{
    if(1) {
        int num_cases;
        scanf("%d", &num_cases);
        for(int i=0; i<num_cases; ++i) {
            u64 start;
            scanf("%lu", &start);
            palin_init(start);

            while(1) {
                u64 p = palin_next();
                if(is_prime_mr(p)) {
                    printf("%lu\n", p);
                    break;
                }
            }
        }
    }
    else {
        palin_init(9999999999999);
        //palin_init(1467083807641);

        while(1) {
            u64 p = palin_next();
    
            if(p == -1) break;
    
            if(is_prime_mr(p))
                printf("%lu\n", p);
        }
    }

    return 0;
}
