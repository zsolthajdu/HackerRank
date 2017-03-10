import sys

# Solution for
# https://www.hackerrank.com/challenges/quicksort1
# It does the partitioning step of quicksort

# Number of values
n = int( input() )

# Read n integers
values = list( map(int, input().split(' ')))
if len(values) != n:
	print( "Not enough data !!\n" )
	exit()

# Partitioning value
part = values[ 0 ]

low = 1
high = n-1
while low < high:
	while values[low] < part:
		if low == n:
			break
		low = low + 1

	while values[high] > part :
		if high == 0:
			break
		high = high - 1

	if low > high:
		break
	values[low], values[high] = values[high], values[low]

# Finally put partitioning value in its place
values[0], values[high] = values[high], values[0]

# Print partitioned series
for i in range(0,n):
	print( str(values[i]), end=" " )
print()

