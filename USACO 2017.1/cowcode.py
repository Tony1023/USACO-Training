import sys
import math
sys.stdin = open("cowcode.in", "r")
sys.stdout = open("cowcode.out", "w")

In = raw_input().split(" ")

s = In[0]
ss = len(s)
N = int(In[1])

n = N

while n > ss:

    coe = (float(n)-0.9) / ss
    power = int(math.log(coe, 2)) + 1
    n -= ss * 2**(power-1)
    n -= 1
    if n == 0:
        n = ss * 2**power


print s[n-1]
