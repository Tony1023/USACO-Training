import sys
sys.stdin = open("hps.in", "r")
sys.stdout = open("hps.out", "w")

N = int(raw_input())

hps = [""] * N

P = [0] * N
S = [0] * N
H = [0] * N

numP = 0
numS = 0
numH = 0

for i in range(N):
    
    hps[i] = raw_input()
    if hps[i] == "P":
        numP += 1
    elif hps[i] == "S":
        numS += 1
    elif hps[i] == "H":
        numH += 1

    P[i] = numP
    S[i] = numS
    H[i] = numH
    
maxTotalWins = 0

for i in range(N):
    TW_P = P[i]
    TW_P += max( numS-S[i], numH-H[i] )
    TW_S = S[i]
    TW_S += max( numP-P[i], numH-H[i] )
    TW_H = H[i]
    TW_H += max( numS-S[i], numP-P[i] )
    maxTotalWins = max(TW_P, TW_S, TW_H, maxTotalWins)

print maxTotalWins


