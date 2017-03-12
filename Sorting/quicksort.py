import sys

# Solution for
# https://www.hackerrank.com/challenges/quicksort2
# Quicksort implementation

def printRange( array, l, h ):
	for i in range(l,h+1):
		print(str(values[i]), end=" ")
	print()

# Partition around the value at index zero.
# Have to keep the original order of values when partitioning!
def partition( values, l, h ):
	# Partitioning value
	p = values[l]
	less = []
	more = []
	for i in range(l + 1, h + 1):
		if values[i] <= p:
			less.append( values[i] )
		else:
			more.append( values[i] )

	if len(less) > 0:
		for i in range(0,len(less)):
			values[l+i] = less[i]
		n = l + i + 1
	else:
		n = l
	values[n] = p
	n = n + 1
	if len(more) > 0:
		for j in range(0,len(more)):
			values[n+j] = more[j]
	return l+len(less)

	# More efficient method, but doesn't keep original order of
	# values on two sides of the partitioning element
	#firsthigh = l+1
	#for i in range(l+1, h+1):
	#	if values[i] < values[p]:
	#		values[i], values[firsthigh] = values[firsthigh], values[i]
	#		firsthigh = firsthigh + 1
	#tmp = values[p]
	#for i in range(l+1, firsthigh):
	#	values[i-1] = values[i]
	#values[firsthigh-1] = tmp
	#return firsthigh-1

def qsort( array, low, high ):
	p = 0;
	if (high-low) > 0:
		p = partition( array, low, high )
		qsort( array, low, p-1 )
		qsort( array, p+1, high)
		printRange(values,low,high)


def quicksort( array ):
	qsort( array, 0, len(array)-1 )

# Number of values
n = int( input() )

# Read n integers
values = list( map(int, input().split(' ')))
if len(values) != n:
	print( "Not enough data !!\n" )
	exit()

quicksort( values )
