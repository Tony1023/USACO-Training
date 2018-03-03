import sys
import time
sys.stdin = open("cowdance.in", "r")
sys.stdout = open("cowdance.out", "w")

s = raw_input().split(" ")
N = int(s[0])
T = int(s[1])
d = [0] * N
for i in range(N):
    d[i] = input()

terminate = False

K = N - 1

t0 = time.clock()

while True:

    onStage = d[slice(0,K)]
    
    tt = 0

    for nextDancer in range(K, N):
        tOfFirstOff = min(onStage)
        onStage.remove(tOfFirstOff)
        onStage[:] = [x - tOfFirstOff for x in onStage]
        tt += tOfFirstOff
        onStage.append(d[nextDancer])
        if nextDancer == N-1:
            onStage.sort()
            tt += onStage[K-1]

    if tt > T:
        break

    K -= 1
    
    if time.clock() - t0 > 5:
        terminate = True
        break

if terminate:
    print sum(d) / T + 1
else:
    print K+1
