
#include <stdio.h>
#include <stdint.h>

typedef unsigned long u64;

u64 sqrmod(u64 base, u64 mod)
{
    if(!(base & 0xFFFFFFFF00000000)) {
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
    //printf("powmod(a=%lu, n=%lu, mod=%lu)\n", a, n, mod);
    u64 runner = a;
    u64 result = 1;
 
    while (n)
    {
        if (n & 1) {
            result = mulmod(result, runner, mod);
            //printf("%lx:%lx\n", (u64)(tmp>>64), (u64)(tmp & 0xFFFFFFFFFFFFFFFF));
            //printf("new result=%lu\n", result);
        }
        runner = sqrmod(runner, mod);
        //printf("new runner=%lu\n", runner);
        n >>= 1;
    }
    //printf("computed result=%lu\n", result);
    return result;
}

int main()
{
    //printf("%lu\n", powmod(4294967296, 2, 34722222222));
    //printf("%lu\n", sqrmod(4294967296, 34722222222));
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

    if(mulmod(13282407956253574712ull, 7557322358563246340ull, 6323947392560ull) == 3185940713760) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(10719928016004921607ull, 13845646450878251009ull, 9381763456855ull) == 2852456033433) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(10009796384580774444ull, 10598342506117936052ull, 6430883704639ull) == 2308098433458) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(2169871353760194456ull, 959683757796537189ull, 3875071599585ull) == 3829796134434) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(8614063320694916486ull, 5278298332222909972ull, 3861829321686ull) == 1032242141102) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(562706585515371056ull, 2854579515609623853ull, 6855858327049ull) == 2915211719751) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(8279505740743114877ull, 17210061324382766539ull, 9466603418168ull) == 3594309628743) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(6301727861784267654ull, 13827821670227353278ull, 862039769647ull) == 171424682191) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(10780909174164501009ull, 8293668300693101108ull, 9423314931851ull) == 3123071573154) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(9534524411267565544ull, 9421399378650073936ull, 339367683806ull) == 226847953872) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(16004282128486014947ull, 576998892785971748ull, 6240812801144ull) == 727737015100) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(179282224262020638ull, 10521311181873170742ull, 2544392020286ull) == 376754492136) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(10542697480666645517ull, 2105473460816588302ull, 4721684150245ull) == 979084844924) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(255513307504807359ull, 10848548338010941605ull, 5914845319196ull) == 5161491545055) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(9880137513987983327ull, 16277473553125026471ull, 6088461429890ull) == 2094127109107) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(17261323542481979200ull, 303708553675737761ull, 4613721988265ull) == 987984672770) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(15561802517685026301ull, 10343431644823323821ull, 3007556563094ull) == 912565414781) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(6916623331954333229ull, 11780487240633441882ull, 1779762581055ull) == 1034409405393) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(388631602056740937ull, 4279149226930994438ull, 3392271965661ull) == 2600934306) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(4841723166798102470ull, 9838800997419312683ull, 6029142497734ull) == 5553956237110) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(500069524988492151ull, 4441612822850768651ull, 8609845848176ull) == 5357908756605) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(9031419907504264226ull, 16757906157732141571ull, 2273129948425ull) == 2168935029371) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(15664521071530223104ull, 16185632551381557786ull, 4920413997353ull) == 1023327217573) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(9903070368395772908ull, 5611477096244309373ull, 6216261628170ull) == 2192153427744) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(14243213630280441346ull, 8263764825410697448ull, 4488524671820ull) == 1401141983548) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(13643134083434632306ull, 8940772357747650202ull, 9313755523500ull) == 4813179511312) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(880900285752294312ull, 7722389635917225344ull, 4418094344241ull) == 659617552668) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(5016806417864038136ull, 8906766797083864475ull, 5743401394281ull) == 3850650716473) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(7687077978384345328ull, 13596239423727787721ull, 6992420451306ull) == 3543885522482) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(13448420169498027334ull, 16679185331815996296ull, 5229990741543ull) == 1546101727764) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(10045795799123098115ull, 2485167665650723397ull, 1919356143461ull) == 1224634046917) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(2376326677702921708ull, 2339308727331107337ull, 4281379536359ull) == 2194970615746) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(17853036404801204319ull, 4220272424309549523ull, 4853875316768ull) == 4511232900717) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(2086286819613974262ull, 14987600693559850137ull, 2728838570412ull) == 254126466726) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(2394513663183469637ull, 8770547468998103209ull, 5315613001462ull) == 2994183781697) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(10225782246228992460ull, 10169432471439397124ull, 6033987186719ull) == 2736331349545) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(4837372594121531785ull, 10435916330122641269ull, 365677206585ull) == 233763628535) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(10810428413684666863ull, 17862947572673605163ull, 2767255928287ull) == 2681842374557) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(2438228693721951365ull, 9871279010369435195ull, 7773975786224ull) == 4210176076423) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(12969555931678516060ull, 9915574830389282439ull, 8029522941498ull) == 6516691458930) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(710701130541265919ull, 8634464414371746750ull, 9643480837240ull) == 6080835804010) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(16956026360216266554ull, 8220959735000762549ull, 6540813080635ull) == 2557016291486) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(3359362946444332099ull, 3733587780451370749ull, 4116143985173ull) == 3645012168923) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(5579142313917102449ull, 17786592339868908823ull, 5937145199007ull) == 4521273781811) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(17073977654843913067ull, 8668977574371742218ull, 7074288468899ull) == 1046578061652) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(7569562740582863568ull, 12899610538993461367ull, 7551695866761ull) == 6245473252656) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(6459629652165914189ull, 1341591687656984763ull, 8796999311990ull) == 3124548334357) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(7899000797871919611ull, 600706459462298683ull, 2814716992680ull) == 746796602673) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(5018426366716572135ull, 6398351797960535114ull, 3092142511880ull) == 2949627475270) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(5548924847274788834ull, 6355699839744949688ull, 7571353401808ull) == 3912644332752) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(16469866554647041514ull, 7590555876499566658ull, 549680689667ull) == 274801537491) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(391987479021712360ull, 12535280332919186456ull, 4400847127952ull) == 3057212747984) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(3525288824196056978ull, 3004822487660561014ull, 6242993477258ull) == 3099260450742) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(10134880325859733029ull, 9085988262254151414ull, 2077385520528ull) == 1762599514878) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(8357047637911565665ull, 6369957256759683160ull, 1624143940041ull) == 220000502365) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(712458774147742288ull, 10672308811378828726ull, 8920280074240ull) == 5084243334368) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(5242594059596266935ull, 4125410103457909156ull, 4839539786038ull) == 1210948717732) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(11956161572522965461ull, 17605111088081687387ull, 1824760556119ull) == 1580086511455) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(8837601322562158995ull, 16132965801156672640ull, 9424842204760ull) == 8240175518120) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(11234918745379507569ull, 11570519301159946435ull, 5905973158125ull) == 3503503505265) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(4163816556085107657ull, 9368205773885521800ull, 3384258653085ull) == 2395279663035) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(11610270786027375995ull, 6901430378283050317ull, 2916620209082ull) == 1310965080893) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(8755225992909256193ull, 4261073501094790522ull, 1507619519671ull) == 1183147372751) { printf("pass\n"); } else { printf("fail\n"); }
    if(mulmod(12348673268316011798ull, 14110472062505353007ull, 4464138994639ull) == 1010284256746) { printf("pass\n"); } else { printf("fail\n"); }

    if(powmod(2380680394120137986ull, 12544782907281296187ull, 3051273725419ull) == 806140026769) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(7084005529475822392ull, 8504304411135945651ull, 7973392482478ull) == 577991927566) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(4359964220898864369ull, 3475134719726822121ull, 9979607686583ull) == 3740056449030) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(14873121220451384576ull, 6213786009837816509ull, 3622134364530ull) == 3112376640926) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(9309822426147737034ull, 5354037140856773547ull, 5467665642510ull) == 2449686714654) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(17019269301441293241ull, 6230701465422807363ull, 8094366660084ull) == 7732773393369) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(12563304941896744493ull, 7726079180689285189ull, 5822525840222ull) == 892529415235) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(920498931285381329ull, 7458960765274627415ull, 6302828258261ull) == 1483408647904) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(680595743792699131ull, 5378862073109126434ull, 309935623713ull) == 251385385936) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(17845773727867811975ull, 4505805757520998942ull, 1909996831557ull) == 1782641392558) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(15068062916485872911ull, 2460610471189195464ull, 5380544960985ull) == 994765421161) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(7448639074071616334ull, 18250649695988690283ull, 6831193963447ull) == 5881882047413) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(11251318265033831046ull, 6355145188517559697ull, 3028373595584ull) == 209804262144) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(16469765349564383710ull, 4959208971000531415ull, 354276011067ull) == 243936756238) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(10777866152199298396ull, 14577952937044288922ull, 4989370060082ull) == 4870233976310) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(10629307849456583333ull, 6691759642600800641ull, 7486580655048ull) == 6935352938549) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(15719389441939741630ull, 6725258105791053441ull, 6535642636601ull) == 1693756297215) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(13161493861905728816ull, 3865531468849293728ull, 4567029951244ull) == 1617652763832) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(183213321586713956ull, 3031830595433678104ull, 5527607252380ull) == 4076030739196) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(13589276637098117567ull, 918785066288146612ull, 8575924359181ull) == 2957117711377) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(15750838395009086517ull, 18081518756688951882ull, 6053930932922ull) == 3363540744605) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(5245181234390949724ull, 8846243548284955834ull, 717325019678ull) == 76753632658) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(1029806289484624785ull, 11860933234587819368ull, 5292813057172ull) == 1837434228765) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(5230089008714087124ull, 12334476998641559304ull, 6860041406974ull) == 2270687866000) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(9948981979131017725ull, 9641729299188735823ull, 6243012515174ull) == 244895680911) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(13466316500101809626ull, 5120677150099710960ull, 7731743035636ull) == 49846922392) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(16261360357918375952ull, 875040283763553738ull, 5544030363431ull) == 2243082850421) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(16137819284894832692ull, 15740534662991636370ull, 4453043630078ull) == 4182889697858) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(2508131206851994948ull, 10838074528767316366ull, 6042947268473ull) == 4762165419976) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(17861613338124358034ull, 10114360270355520216ull, 13016598104ull) == 9420574608) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(2972348313323407881ull, 4817415169206660711ull, 2740126479170ull) == 2540705347181) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(11401602346333331622ull, 13820878085630129571ull, 6513066450639ull) == 5809309996581) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(7287859437363475767ull, 17902301845812829475ull, 9363070156538ull) == 9217462228561) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(460713800973634058ull, 1748361513347568931ull, 3424277038443ull) == 3160912057298) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(11816808158907855545ull, 11148924412154433735ull, 6299633675526ull) == 6032685613391) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(11854095336618496899ull, 7086396064703505180ull, 8081043275116ull) == 4482662616089) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(13779621380642387031ull, 9291035729528901749ull, 4851941970928ull) == 1173756416919) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(6149714372719593819ull, 18435067521514958389ull, 4710887101018ull) == 1080046026027) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(1892456232589403662ull, 4117828922016553775ull, 392606350888ull) == 46734727712) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(5888269674143237919ull, 10086092363069543166ull, 550381597202ull) == 121197438461) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(6294555412650643753ull, 14534458748839109079ull, 9628495581657ull) == 2997816177889) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(4840535154134637456ull, 7402029445662424545ull, 7994293318869ull) == 7889161043886) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(381105978414618226ull, 14943303445831776872ull, 3239035869380ull) == 1193094043336) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(3590603796692511406ull, 5401428022900764446ull, 6571951474561ull) == 876859024959) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(1562888693774496250ull, 14129588865063169556ull, 2961126025787ull) == 1951386476730) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(12801182192819992405ull, 11116249758219365348ull, 6529014344342ull) == 4936484555331) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(11276055256514179586ull, 11919514506409756394ull, 5325043785449ull) == 5224485698471) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(2611386102996607377ull, 11200604910114431530ull, 9773915997817ull) == 8062837567476) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(3887900140126895148ull, 3318374966081208308ull, 7437803434483ull) == 3314193600115) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(14937065880844993398ull, 15099800978561893153ull, 1817989367756ull) == 423917542324) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(4589549588820608431ull, 2336851009947407792ull, 9420908856085ull) == 2385822240971) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(11063439092116079922ull, 11689249425742318003ull, 3052209159264ull) == 2558311703616) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(8817038067873383884ull, 14708023529671459659ull, 1689187913029ull) == 1642954140061) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(13133259635724106637ull, 1332160604193781434ull, 1092112538698ull) == 837173163091) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(7207122370780591417ull, 12508055299492486839ull, 7359374076185ull) == 3344191788238) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(4834624895354161427ull, 6000102820938312196ull, 7922057801667ull) == 5691596690104) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(13891243379042683442ull, 406699617827227136ull, 5363811781294ull) == 133555419240) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(306805465510459709ull, 11584170451694616183ull, 6459243871844ull) == 799535445005) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(2218373771523121310ull, 13140431018936371056ull, 2806386643195ull) == 2386452633290) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(13099064542574299780ull, 16542844962909263485ull, 1625162946113ull) == 1029834135674) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(17656316011991447075ull, 15502547950085111743ull, 4742442578721ull) == 3171652815242) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(13425395477599568004ull, 8217013835295996654ull, 7545045580648ull) == 2031584565272) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(1627732739429420861ull, 2677252178074804721ull, 4448059652992ull) == 149780137725) { printf("pass\n"); } else { printf("fail\n"); }
    if(powmod(4236261306732543660ull, 14233134079996680789ull, 9759933933759ull) == 7786948835241) { printf("pass\n"); } else { printf("fail\n"); }

    return 0;
}
