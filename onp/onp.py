#!/usr/bin/env python

# http://www.spoj.com/problems/ONP/
# ONP - Transform the Expression

expr = None
answ = ''

def go():
    global expr, answ

    #print "entered go on: %s" % expr

    # consume left hand side
    # lhs is a subexpr
    if expr[0] == '(':
        expr = expr[1:] # eat '('
        go()            # eat inside
        expr = expr[1:] # eat ')'
    # lhs is an id
    else:
        answ += expr[0]
        expr = expr[1:]

    # consume operator
    op = expr[0]
    expr = expr[1:]

    # consume right hand side
    # rhs is a subexpr
    if expr[0] == '(':
        expr = expr[1:] # eat '('
        go()            # eat inside
        expr = expr[1:] # eat ')'
    # rhs is an id
    else:
        answ += expr[0]
        expr = expr[1:]

    # and print the op
    answ += op


n = int(raw_input())

for z in range(n):
    answ = ''
    expr = raw_input()
    if expr[0]=='(' and expr[-1]==')':
        expr = expr[1:-1]
    go()
    print answ


