/* helper script for palindrome prime puzzle
    language is pari/gp (see pari.math.u-bordeaux.fr)

    load with `\r palprim.gp`
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

survey() = {
    divs = 100000; /* number of ways to divide up the 10^13 space */
    cover = 10000; /* number of primes to test at each sample point */

    x_plot_vals = [];
    y_plot_vals = [];

    for(k=1, divs,

        found = 0;

        left = 2 + (k*(10^13))/divs;

        /* don't waste time on numbers with even digits 
            -> divisible by 11 */
        if(length(Str(left)) % 2,

            left = nextprime(left);
            for(k=1, cover,
                if(isPalindrome3(left),
                    found = 1;
                    break;
                );
    
                left = nextprime(left+1);
            );
        );

        if(found,
            print(left, "...X");
            x_plot_vals = concat(x_plot_vals, k);
            y_plot_vals = concat(y_plot_vals, left)
        ,
            print(left, "...");
        );
    );

    print("graphing...");
    /*
    print("x values: ", x_plot_vals);
    print("y values: ", y_plot_vals);
    */
    plotpointsize(-1, 100);
    plothraw(x_plot_vals, y_plot_vals);
    plotpointsize(-1, 100);
}



