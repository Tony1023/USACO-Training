import sys
sys.stdin = open("cowdance.in", "r")
sys.stdout = open("cowdance.out", "w")

s = raw_input().split(" ")
N = int(s[0])
T = int(s[1])
d = [0] * N
for i in range(N):
    d[i] = input()


totalTime = sum(d)

print totalTime / T + 1
