
import sys
from collections import Counter

#
# https://www.hackerrank.com/challenges/s10-quartiles
#

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


n = int( input() )

# Read n integers
lst = list(map(int, input().split() ) )

if len(lst) != n:
	print( "Not enough data..\n" )

lst.sort()

mid1 = len(lst)/2 - 1
if 1 == (len(lst) & 1):
	mid2 = mid1 + 2 # Odd item count, skip middle element
else:
	mid2 = mid1 + 1

q1 = median( lst[: int(n/2)] )
q2 = median( lst )
q3 = median( lst[-int(n/2):] )

print( int(q1) )
print( int(q2) )
print( int(q3) )

