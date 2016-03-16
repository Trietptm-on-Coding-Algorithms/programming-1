#!/usr/bin/env python

import re
import sys

if not sys.argv[1:]:
    print "supply header file"
    sys.exit(-1)

print '#include <stdio.h>'
print '#define stringify2(x) #x'
print '#define stringify(x) stringify2(x)'
print 'int main(void)'
print '{'

with open(sys.argv[1]) as f:
    for line in f.readlines():
        line = line.rstrip()
        
        m = re.match(r'^#define ([\w]+) (.*)$', line)

        if m:
            (name, value) = m.group(1,2)
            #print "%s=%s" % (name, value)

            print "#ifdef %s" % name
            print "    printf(\"%s: %%s\\n\", stringify(%s));" % (name, name)
            print "#else"
            print "    printf(\"%s: NOT DEFINED\\n\");" % name
            print "#endif"

print '    return 0;'
print '}'
