/* helper script for palindrome prime puzzle
    language is pari/gp (see pari.math.u-bordeaux.fr)

    load with `\r palprim.gp`

    is it smarter to:
    iterate over primes and test palindrome?
    or iterate over palindromes and test primality?

    for a 13-digit number, there are 10^7 palindromes
    but there are pi(13)-pi(12) = 346,065,536,839-37,607,912,018=308,457,624,821 primes

    and that disregards the ease at which to generate the next palindrome vs. the
    ease at which to compute the next prime

*/


/* 41889, 42524, 37865 */
isPalindrome1(n) = {
    return( n == eval(concat(Vecrev(Str(n)))) );
}

/* 67493, 67071 */
isPalindrome2(n) = {
    d = digits(n, 10);
    return( d == Vecrev(d) );
}

/* fastest */
/* 37495, 37550 */
isPalindrome3(n) = {
    return( Str(n) == concat(Vecrev(Str(n))) );
}


count = 1
pivot = 1
limit_lo = 1
limit_hi = 9
num_pp = 0

palindrome_next() = {
    count += 1;
   
    /* print("comparing count=",count," with limit_hi=",limit_hi); */

    if(count > limit_hi,
        if(pivot,
            pivot = 0;
            count = limit_lo;
        ,
            pivot = 1;
            limit_lo = limit_hi + 1;
            limit_hi = limit_lo * 10 - 1;
            count = limit_lo;
        );
    );

    s = Str(count);
    if(pivot, 
        left = Str(s);
        right = List(Vec(s));
        listpop(right);
        if(length(right),
            right = concat( Vecrev(right) );
        ,
            right = "";
        );
        return(eval(concat(left, right)));
    ,
        return(eval(concat(s, concat(Vecrev(s)))));
    );
}

search() = {
    t0 = getabstime();
    iter = 0;

    while(1,
        pal = palindrome_next();

        if(pal >= 10000000000001,
            break;
        );

        /* even digits -> divisible by 11 */
        if(logint(pal, 10) % 2 != 0,
            next;
        );

        if(isprime(pal),
            num_pp += 1;
            print(pal);
        );
    );

    t1=getabstime();
    print("time=", t1-t0,"ms");
    print("total P.P. found=", num_pp);
}

