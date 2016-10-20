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

f = open(sys.argv[1])
lines = f.readlines()
f.close()

W, N = map(lambda x: int(x), lines[0].split(" "))
graph = [[10000 for i in range(W)] for j in range(W)]
for i in range(W):
	graph[i][i]=0

for line in lines[1:]:
	s,t, k= map(int, line.split(" "))
	graph[s-1][t-1]=k

for k in range(W):
	for i in range(W):
		for j in range(W):
			graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j])
	print k

values=10000
for i in range(W):
	for j in range(W):
		if graph[i][j]<values:
			values=graph[i][j]
print values

