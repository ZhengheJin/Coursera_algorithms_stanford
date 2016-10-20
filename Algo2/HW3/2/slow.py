import sys

def lookfor(value,table,size,number):
	if size == 0 or number ==0: 
		table[(size,number)]=0
		return table[(size,number)]
	elif (size,number) in table.keys():
		return table[(size,number)]
	else:
		tmp1=lookfor(value,table,size,number-1)
		if size > value[number-1][1]:
			tmp2=lookfor(value,table,size-value[number-1][1],number-1)+value[number-1][0]
		else:
			tmp2=0
		table[(size,number)]=max(tmp1,tmp2)
		return table[(size,number)]


if __name__ == '__main__':
	f=open("knapsack_big.txt",'r')
	line=f.readline()
	sys.setrecursionlimit(2100)
	[size,number]=map(int,open("knapsack_big.txt",'r').readline().split())
	value=[map(int,x.split(' ')) for x in open("knapsack_big.txt",'r').read().split('\n')[1:-1]]
	print size
	print number
	print value
	table={}
	x=lookfor(value,table,size,number)
	print x
