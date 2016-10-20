def connects(edge, mst):
    source, dest = edge
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
        weight=nx.get_edge_attributes(G,"weight")
	for edge in edges:
		if connects(edge, mst) and (not min_edge or weight[edge] < weight[min_edge]):
			min_edge=edge
	return min_edge


def prim_mst(G):
	mst=[]
        edges=G.edges()
        weight=nx.get_edge_attributes(G,"weight")
##	edges=[] # reformation of edges, not G.edges()
##	for v in G.nodes():
##		for neighbor in G.neighbors(v):
##                    #use (a,b,c) to group data together
##			edges.append((v,neighbor,G.edge[v][neighbor]["weight"])) # G.edge(i,j)
        min_edge=min(edges, key=lambda edge: weight[edge])
	mst = [min_edge]
        edges.remove(min_edge)
    #    #len(graph)=499, since the last node won't have any point connect to it.
    #    print len(graph)

        while len(mst) < G.number_of_nodes()-1:
		min_edge = min_connecting_edge(mst,edges)
		edges.remove(min_edge)
		mst.append(min_edge)

	return mst

	
if __name__ == '__main__':
    import networkx as nx
    G=nx.Graph()
    f=open("edges.txt",'r')
    line=f.readline()
    numbers=map(int,line.split())
    
    for i in range(numbers[1]):
        line=f.readline()
        num=map(int,line.split())
        if not num[0] in G.nodes():
            G.add_node(num[0])
        if not num[1] in G.nodes():
            G.add_node(num[1])
        G.add_edge(num[0],num[1],weight=num[2])
    #for i in range(10):
    #    print Graph[i+1]
    
    weight=nx.get_edge_attributes(G,"weight")
    mst=prim_mst(G)
    sum = 0
    for i in range(len(mst)):
    	sum = sum + weight[mst[i]]
    #print mst
    print sum
