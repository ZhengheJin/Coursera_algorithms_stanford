import re
from operator import itemgetter, attrgetter, methodcaller
class Entry:
    def __init__(self, id,weight, length):
        self.id=id
        self.weight=weight
        self.length=length
        self.diff=weight-length
        self.ratio=float(weight)/length

f=open('jobs.txt','r')

number=int(f.readline())
#number=10
item_set=[]
#for i in range(number):
for i in range(number):
    numbers=map(int,f.readline().split())
    item_set.append(Entry(i,numbers[0],numbers[1]))

for i in range(0):
    print item_set[i].id,item_set[i].diff, item_set[i].ratio
        
item_set=sorted(item_set, key=attrgetter('weight'),reverse=True)
item_set=sorted(item_set, key=attrgetter('diff'),reverse=True)

for i in range(0):
    print item_set[i].id,item_set[i].diff, item_set[i].weight
        
   # print numbers
time = 0
sum = 0
for i in range(number):
    time = time+item_set[i].length
    sum = sum+time*item_set[i].weight

print sum
f.close()

