import sys
sys.stdin = open("cowdance.in", "r")
sys.stdout = open("cowdance.out", "w")

s = raw_input().split(" ")
N = int(s[0])
T = int(s[1])
d = [0] * N
for i in range(N):
    d[i] = input()

terminate = False

K = sum(d) / T

tt = T + 1

while tt > T:

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
    K += 1

print K-1
