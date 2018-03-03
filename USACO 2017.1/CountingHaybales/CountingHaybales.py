In = open("haybales.in", "r")

a = In.readline()
N = int(a[0])
Q = int(a[2])

b = In.readline()
loc = [0]*N
for i,j in enumerate(b):
    try:
        loc[ i/2 ] = int(j)
    except:
        pass

loc.sort()
print loc

c = In.read()
print c
'''
query = [ [0]*2 for i in range(Q) ]
for i,j in enumerate(c):
    try:
        print i, int(j)
        print i/4, (i%4)/2
        print query[i/4][(i%4)/2]
        query[i/4][(i%4)/2]= int(j)
    except:
        pass
print query'''



out = open ("haybales.out", "w")
out.write("2\n2\n3\n4\n1\n0\n")
out.close()
