
import sys
from collections import Counter

#
# https://www.hackerrank.com/challenges/s10-basic-statistics
# https://www.hackerrank.com/challenges/s10-weighted-mean


def median( vec ):
	"""finds the 'middle-most' value of v"""
	n = len(vec)
	sorted_v = sorted(vec)
	midpoint = n // 2
	if n % 2 == 1:
		# if odd, return the middle value
		return sorted_v[midpoint]
	else:
		# if even, return the average of the middle values
		lo = midpoint - 1
		hi = midpoint
		return (sorted_v[lo] + sorted_v[hi]) / 2

def mode(x):
	"""returns a list, might be more than one mode"""
	counts = Counter(x)
	#a = counts.most_common(1)
	#return a[0]
	max_count = max(counts.values())
	r = []
	for k,v in counts.items():
		if v == max_count:
			r.append( k )
	return r
	#return [x_i for x_i, count in counts.elements() if count == max_count]

n = int( input() )

# Read n integers
lst = list(map(int, input().split() ) )

if len(lst) != n:
	print( "Not enough data..\n" )

# Mean
#print( sum( lst ) / n )

# Median
#print( median( lst ) )

# Mode
#print( min( mode( lst ) ) )

# Weighted mean
weights = list(map(int, input().split() ) )

if len(lst) != len(weights):
	exit(0)

szum = 0
for n, w in zip( lst, weights ):
	szum = szum + n*w
print( '{:0.1f}'.format( szum / sum(weights) ) )



