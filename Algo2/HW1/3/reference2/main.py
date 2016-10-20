from random import choice

class Vertex(object):
    def __init__(self, label):
        self.label = label
        self.adjacent = []

    def __repr__(self):
        return str(self.label)

def connects(edge, mst):
    source, dest, _ = edge

    for s, d, _ in mst:
        if source == s or source == d or \
           dest == s or dest == d:
            return True

    return False

def min_connecting_edge(mst, edges):
    min_edge = None
    for edge in edges:
        if connects(edge, mst) \
           and (not min_edge or edge[2] < min_edge[2]):
            min_edge = edge
    return min_edge

def prim_mst(vertexes):
    mst = []

    edges = []
    for v in vertexes:
        for adjacent in v.adjacent:
            edges.append((v, adjacent[0], adjacent[1]))

    if not edges:
        return mst

    mst = [edges.pop()]

    while len(mst) < len(vertexes) - 1:
        min_edge = min_connecting_edge(mst, edges)
        edges.remove(min_edge)
        mst.append(min_edge)

    return mst

if __name__ == '__main__':
    f=open("edges.txt",'r')
    line=f.readline()
    numbers=map(int,line.split())
    vertex_list=[]
    vertex_num_list=[]
    for i in range(numbers[1]):
        line=f.readline()
        num=map(int,line.split())
        s=Vertex(num[0])
        t=Vertex(num[1])
        if not num[0] in vertex_num_list:
            vertex_list.append(s)
            vertex_num_list.append(num[0])
        if not num[1] in vertex_num_list:
            vertex_list.append(t)
            vertex_num_list.append(num[1])

        Vertex(num[0]).adjacent.append((Vertex(num[1]),int(num[2])))

    mst = prim_mst(vertex_list)

    for i in range(numbers[0]):
        print(vertex_list[i].adjacent)
    
  #  print vertex_list
    
#    MST={}
#    #for i in range(numbers[0]):
#    #    2:
#    a = Vertex('a')
#    b = Vertex('b')
#    c = Vertex('c')
#    d = Vertex('d')
#    e = Vertex('e')
#
#    a.adjacent = [(b, 1), (c, 3), (d, 2)]
#    b.adjacent = [(e, 2)]
#    c.adjacent = [(e, 3)]
#
#    mst = prim_mst([a, b, c, d, e])
#
    print mst
