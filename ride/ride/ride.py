'''
ID: tony1021
PROG: ride
LANG: PYTHON
'''


import sys

sys.stdin = open('ride.in', 'r')
#sys.stdout = open('ride.out', 'w')

comet = raw_input()
group = raw_input()

comet_product = 1
group_product = 1

for i, j in enumerate(comet):
    comet_product *= ord(j) - 64

for i, j in enumerate(group):
    group_product *= ord(j) - 64

if (comet_product - group_product) % 47 == 0:
    print "GO"
else:
    print "STAY"
