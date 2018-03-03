import sys

In = open ("angry.in", "r")

a = In.readline().split(" ")

N = int(a[0])
K = int(a[1])

a = In.read().split("\n")

haybales = [0]*N

for i,j in enumerate(a):
    try:
        haybales[i] = int(j)
    except:
        pass

haybales.sort()

def passedNum(p):
    lo = 0
    hi = N-1
    if p >= haybales[hi]:
        return hi
    while lo < hi-1:
        mid = (lo+hi)/2
        if haybales[ (lo+hi)/2 ] < p:
            lo = mid
        elif haybales[ (lo+hi)/2 ] > p:
            hi = mid
        else:
            return mid
    return lo

terminate = False
R = 0

while not terminate:
    R += 1
    pos = haybales[0]

    for i in range(K):
        pos += 2*R
        n = passedNum(pos)+1
        if n >= N:
            terminate = True
        else:
            pos = haybales[n]

    

sys.stdout = open("angry.out", "w")
print R
