from operator import attrgetter,itemgetter, methodcaller
from sets import Set

class Edge():
    def __init__(self,source,dest,weight):
        self.source=source
        self.dest=dest
        self.weight=weight

    def __repr__(self):
        return str(self.source)+" "+str(self.dest)+" "+str(self.weight)


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
def kruskal_mst(edges):
    mst=[]
    edges=sorted(edges, key=attrgetter('weight','source','dest'))
    edge_count=0

    nodes_set={}
    for node in range(1,501):
        nodes_set[node]=[]
        nodes_set[node].append(node)

    for edge in edges:
        if not edge.source in nodes_set[edge.dest]:
            nodes_set[edge.source]= nodes_set[edge.source]+nodes_set[edge.dest]
            ## every list will be updated.
            for mid in nodes_set[edge.source]:
                nodes_set[mid]=nodes_set[edge.source]
            edge_count = edge_count+1
            if edge_count == 497:
                #print len(mst)
                #print "hello2"
                #for node in range(1,501):
                #   print node,nodes_set[node]
                #for i in mst:
                #   print i 
                print edge
                return mst
            mst.append(edge)
            #print len(mst)
            #print edge_count
    return mst

	
if __name__ == '__main__':
    f=open("clustering1.txt",'r')
    line=f.readline()
    numbers=map(int,line.split())

 


    edges=[]
    mst=[]
    for line in f.readlines():
        num=map(int,line.split())
        edges.append(Edge(num[0],num[1],num[2]))

    mst=kruskal_mst(edges)
    sum = 0
    #for edge in mst:
    #	sum = sum + edge.weight
    #print mst
    print sum
