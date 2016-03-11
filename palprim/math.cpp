
#include <stdio.h>
#include <stdint.h>

typedef unsigned long u64;

u64 sqrmod(u64 base, u64 mod)
{
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

u64 mulmod(u64 a1, u64 a2, u64 mod)
{
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

int main()
{
    /*
    printf("%d\n", sqrmod16(65000, 29)); // should be 5
    return 0;

    printf("%lu\n", sqrmod(12, 7));
    printf("%lu\n", sqrmod(16, 7));
    return 0;
    */
    //printf("%lu\n", sqrmod(0x200000002, 9195069598377)); // should be 148391509588
    //return 0;

    if(sqrmod(12102542517240510471ull, 6243012515174ull) == 2889112689455) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(13466316500101809626ull, 4883458280658ull) == 4693480962184) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(15910664805729092268ull, 7731743035636ull) == 4172141354080) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(16261360357918375952ull, 834503444446ull) == 733248818876) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(17943246633683331933ull, 5544030363431ull) == 1186997980434) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(16137819284894832692ull, 4453043630078ull) == 3968050979690) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(2508131206851994948ull, 6042947268473ull) == 5337570878154) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(17861613338124358034ull, 9645805616717ull) == 5858774938284) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(17201967723014466232ull, 13016598104ull) == 12361908672) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(2972348313323407881ull, 4594245118338ull) == 795649366341) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(2873230863022858977ull, 6513066450639ull) == 4391815946382) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(7287859437363475767ull, 9363070156538ull) == 5431163420285) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(460713800973634058ull, 1667367471072ull) == 521217581188) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(15972507062849561469ull, 3424277038443ull) == 2429541018534) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(11816808158907855545ull, 6299633675526ull) == 4937010314299) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(11854095336618496899ull, 6758113922790ull) == 5109553269621) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(8473588033248322606ull, 8860622148064ull) == 3914427524164) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(17549442011819353908ull, 4851941970928ull) == 4060282850144) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(6149714372719593819ull, 4710887101018ull) == 2779375004821) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(1892456232589403662ull, 3927067682282ull) == 739359868806) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(13939004657691334560ull, 392606350888ull) == 195340245856) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(5888269674143237919ull, 9618847239560ull) == 5038765339841) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(14263314412684773059ull, 550381597202ull) == 160084402071) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(6294555412650643753ull, 9628495581657ull) == 3769902790834) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(4840535154134637456ull, 7059125371611ull) == 3431934415110) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(8382624111127037595ull, 363450983442ull) == 208947032205) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(14943303445831776872ull, 3239035869380ull) == 22172219704) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(3590603796692511406ull, 5151203177357ull) == 3850362256964) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(16366212963803168886ull, 6571951474561ull) == 3252859343870) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(1562888693774496250ull, 2961126025787ull) == 2212211667068) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(12801182192819992405ull, 6529014344342ull) == 5408343456159) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(11276055256514179586ull, 5325043785449ull) == 2143083470010) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(2611386102996607377ull, 9773915997817ull) == 4717928311890) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(3887900140126895148ull, 3164648977357ull) == 1750279127172) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(16760179410310971343ull, 7437803434483ull) == 6737937722363) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(14937065880844993398ull, 1817989367756ull) == 1075081137104) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(4589549588820608431ull, 2228594789454ull) == 1800763181875) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(9878538924678609358ull, 3052209159264ull) == 2295271421284) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(8817038067873383884ull, 1689187913029ull) == 80827661672) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(13133259635724106637ull, 1270447353547ull) == 1052258562716) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(10576355045395942467ull, 1092112538698ull) == 705121813535) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(7207122370780591417ull, 7359374076185ull) == 2965098487854) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(4834624895354161427ull, 5722143956125ull) == 2332103560204) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(8306879681440797608ull, 387858980014ull) == 299971254790) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(14071450254769147284ull, 5363811781294ull) == 3709583942414) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(306805465510459709ull, 6459243871844ull) == 2569593495561) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(2218373771523121310ull, 2806386643195ull) == 2474006688345) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(13099064542574299780ull, 1625162946113ull) == 942791456580) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(17656316011991447075ull, 4742442578721ull) == 2601307965334) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(13425395477599568004ull, 7836355052276ull) == 3666941476008) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(7911553714774416372ull, 1552326907567ull) == 369992721502) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(2677252178074804721ull, 4448059652992ull) == 1378803957089) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(4236261306732543660ull, 9759933933759ull) == 3367970482437) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(2618588061369225161ull, 7280172955329ull) == 1168310369164) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(3800878365966898022ull, 7315241272909ull) == 1148912060067) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(28704925899789303ull, 9518223739144ull) == 1905357711001) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(4065166282796913075ull, 8045383220343ull) == 2415748291443) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(2583882807944616573ull, 1359151168182ull) == 1158751521369) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(10867206287866759060ull, 5717938321219ull) == 4007553455190) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(9713674164571999352ull, 1464259625293ull) == 1064996499650) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(16271277314810136216ull, 6443923618189ull) == 905140314240) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(7696386966394613141ull, 7617160293479ull) == 5271673680980) { printf("pass\n"); } else { printf("fail\n"); }
    if(sqrmod(728387262263138214ull, 314736002284ull) == 264600923620) { printf("pass\n"); } else { printf("fail\n"); }

    return 0;
}
