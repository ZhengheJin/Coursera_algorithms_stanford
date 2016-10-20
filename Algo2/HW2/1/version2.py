from operator import attrgetter,itemgetter, methodcaller

class Edge():
    def __init__(self,source,dest,weight):
        self.source=source
        self.dest=dest
        self.weight=weight

    def __repr__(self):
        return str(self.source)+" "+str(self.dest)+" "+str(self.weight)

class List_of_list(list): #inheritance from list
    def __init__(self):
        self=[]

    def add(self,list1):
        self.append(list1)
    def find(self, t):
        for x in self:
            for y in x:
                if t==y:
                    return x
        return []

    def merge(self,t1,t2):
        list1=self.find(t1)
        list2=self.find(t2)
        if list1!=[] and list2!=[]:
            self.remove(list1)
            self.remove(list2)
            self.append(list1+list2)

def kruskal_mst(edges):
    mst=[]
    edges=sorted(edges, key=attrgetter('weight','source','dest'))
    edge_count=0

    nodes_set=List_of_list()
    for node in range(1,501):
        nodes_set.add([node])

    for edge in edges:
        if not edge.source in nodes_set.find(edge.dest):
            nodes_set.merge(edge.source,edge.dest)## every list will be updated.
            edge_count = edge_count+1
            if edge_count == 497:
                #print len(mst)
                #print "hello2"
                #for node in range(1,501):
                #   print node,nodes_set[node]
                #for i in mst:
                #   print i 
                print edge
                print nodes_set
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
