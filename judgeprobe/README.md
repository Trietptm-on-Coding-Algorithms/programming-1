I'm trying to match my compiler to the online judge's compiler.

The current strategy is to find all preprocessor macros your compiler with `g++ -dM -E - < /dev/null > input.h` or `echo | g++ -dM -E -`.

Some example results are in input_clang-700.1.81.h, 

Now gen.h will take this header, and generate a probe c++ program that prints out those macros when run on the online judge, which can then be diff'd with yours.

To illustrate the point, a small example follows. But generate your own input.h for your compiler and run it through gen.py to make a probe program.


```
#include <stdio.h>

int main()
{
    #ifdef __VERSION__
    printf("__VERSION__: %s\n", __VERSION__);
    #endif
    #ifdef __VERSION
    printf("__VERSION: %s\n", __VERSION);
    #endif
    #ifdef __x86_64
    printf("__x86_64: %d\n", __x86_64);
    #endif
    #ifdef __UINT64_TYPE__
    printf("__UINT64_TYPE__: %s\n", #__UINT64_TYPE__)
    #endif
    return 0;
}
```

And for some judges it prints:

* ideone "c++, clang 3.7":
__VERSION__: 4.2.1 Compatible Debian Clang 3.7.0 (trunk)
* ideone "c++, gcc 4.3.2"
__VERSION__: 4.3.2
* ideone "c++, gcc 5.1.1"
__VERSION__: 5.1.1 20150711

Note that, as of this time, they're not 64-bit.


