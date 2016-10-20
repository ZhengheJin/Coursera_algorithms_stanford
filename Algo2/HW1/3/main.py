def connects(edge, mst):
    source, dest, _ = edge
    node = []
    for i in range(len(mst)):
        if not mst[i][0] in node:
            node.append(mst[i][0])
        if not mst[i][1] in node:
            node.append(mst[i][1])
    if ((source in node) and (not dest in node)) or ((not source in node) and (dest in node)):
        return True
#    for s, d, _ in mst:
#        if source == s or source == d or \
#           dest == s or dest == d:
#            return True
#
    return False

def min_connecting_edge(mst,edges):
	min_edge = None
	for edge in edges:
		if connects(edge, mst) and (not min_edge or edge[2] < min_edge[2]):
			min_edge=edge
	return min_edge


def prim_mst(graph):
	mst=[]
	edges=[]
	for v in graph.keys():
		for adjacent in graph[v].keys():
			edges.append((v,adjacent,graph[v][adjacent]))
	edges=sorted(edges, key=lambda (i,j,k):k, reverse=True)
	mst = [edges.pop()]
    #    #len(graph)=499, since the last node won't have any point connect to it.
    #    print len(graph)

	while len(mst) < len(graph):
		min_edge = min_connecting_edge(mst,edges)
		edges.remove(min_edge)
		mst.append(min_edge)

	return mst

	
if __name__ == '__main__':
    f=open("edges.txt",'r')
    line=f.readline()
    numbers=map(int,line.split())
    Graph={}
    
    for i in range(numbers[1]):
        line=f.readline()
        num=map(int,line.split())
        if not num[0] in Graph.keys():
            Graph[num[0]]={}
        Graph[num[0]][num[1]]=num[2]
    
    #for i in range(10):
    #    print Graph[i+1]
    
    mst=prim_mst(Graph)
    sum = 0
    for i in range(len(mst)):
    	sum = sum + mst[i][2]
    #print mst
    print sum
