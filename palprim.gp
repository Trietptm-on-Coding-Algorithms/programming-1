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

search(thread) = {
    t0 = getabstime();

    if(thread == 0, 
        forprime(p=2,                        11, if(isPalindrome3(p), print(p)));
        forprime(p=101,                     999, if(isPalindrome3(p), print(p)));
        forprime(p=10001,                 99999, if(isPalindrome3(p), print(p)));
        forprime(p=1000001,             9999999, if(isPalindrome3(p), print(p)));
        forprime(p=100000001,         999999999, if(isPalindrome3(p), print(p)));
        forprime(p=10000000001,     99999999999, if(isPalindrome3(p), print(p)));
        forprime(p=1000000000001, 2500000000000, if(isPalindrome3(p), print(p)));
    );

    if(thread == 1,
        forprime(p=2500000000001, 5000000000000, if(isPalindrome3(p), print(p)))
    );

    if(thread == 2,
        forprime(p=5000000000001, 7500000000000, if(isPalindrome3(p), print(p)))
    );

    if(thread == 3,
        forprime(p=7500000000001, 9999999999999, if(isPalindrome3(p), print(p)))
    );

    t1=getabstime();
    print(t1-t0);
}

