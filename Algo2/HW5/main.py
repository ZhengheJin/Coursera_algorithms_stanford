"""
This problem also asks you to solve a knapsack instance, but a much bigger one.
Download the text file here. This file describes a knapsack instance, and it has the following format:
[knapsack_size][number_of_items]
[value_1] [weight_1]
[value_2] [weight_2]
...
For example, the third line of the file is "50074 834558", indicating that the second item has value 50074 and size 834558, respectively. As before, you should assume that item weights and the knapsack capacity are integers.
This instance is so big that the straightforward iterative implemetation uses an infeasible amount of time and space. So you will have to be creative to compute an optimal solution. One idea is to go back to a recursive implementation, solving subproblems --- and, of course, caching the results to avoid redundant work --- only on an "as needed" basis. Also, be sure to think about appropriate data structures for storing and looking up solutions to subproblems.
"""


import sys
import math
import time
start_time=time.time()
def tsp_rec_solve(d):
    def rec_tsp_solve(c, ts):
        assert c not in ts
        if ts:
            return min((d[lc][c] + rec_tsp_solve(lc, ts - set([lc]))[0], lc)
                       for lc in ts)
        else:
            return (d[0][c], 0)
 
    best_tour = []
    c = 0
    cs = set(range(1, len(d)))
    while True:
        l, lc = rec_tsp_solve(c, cs)
        print l, lc 
        if lc == 0:
            break
        best_tour.append(lc)
        c = lc
        cs = cs - set([lc])
 
    best_tour = tuple(reversed(best_tour))
 
    return best_tour

f = open(sys.argv[1])
lines = f.readlines()
f.close()

W = int(lines[0].split(" ")[0])
print W
x=[]
y=[]
for i in range(W):
	j,k=map(float, lines[i+1].split(" "))
	x.append(j)
	y.append(k)

dist = [[math.sqrt((x[i]-x[j])**2+(y[i]-y[j])**2) for i in range(W)] for j in range(W)]
#print x
#print y
#print dist

print tsp_rec_solve(dist)
##for i in range(W):
##	graph[i][i]=0
##
##for line in lines[1:]:
##	s,t, k= map(int, line.split(" "))
##	graph[s-1][t-1]=k
##
##for k in range(W):
##	for i in range(W):
##		for j in range(W):
##			graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j])
##	print k
##
##values=10000
##for i in range(W):
##	for j in range(W):
##		if graph[i][j]<values:
##			values=graph[i][j]
##print values
print ("--- %s seconds ---" %(time.time()-start_time))
