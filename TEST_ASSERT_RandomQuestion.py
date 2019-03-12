#!/usr/bin/env python
#coding=utf-8

from os import system

system('g++ TEST_RandomQuestion.cpp RandomQuestion.cpp Number.cpp Random.cpp -o tmp')
system('.\\tmp.exe')
system('rm tmp.exe')

f = open('tmp.txt', 'r')
txt = f.readlines()
f.close()
for i in txt:
    j = i.split()
    a = abs(eval(j[0]) - eval(j[1]))
    if a > 1e-4:
        print(i, a)

system('rm tmp.txt')