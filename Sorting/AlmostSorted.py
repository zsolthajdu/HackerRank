#!/usr/bin/python3

import sys

# Solution for
# https://www.hackerrank.com/challenges/almost-sorted

# Number of values
n = int( input() )

# Read n integers
values = list( map(int, input().split(' ')))
if len(values) != n:
	print( "Not enough data !!\n" )
	exit()

descends = []
curr = -1
inDescending = False
# Go through values and find subsequences with descending values
# We can only have two of those at the most.
for i in range( len(values)-1 ) :
	if values[i] > values[i+1]:
		if False==inDescending:
			curr = curr + 1
			descends.append( [] )
			inDescending = True
		descends[curr].append(i)
	else:
		if inDescending:
			inDescending = False

if len( descends ) == 0 :
	# All sorted
	print( "yes" )
	exit()
elif len( descends ) == 2 :
	# Two descending sequences. It will only work if they are both just a single
	# value and swapping them makes the full sequence ascending.
	if 1==len(descends[0]) and 1==len(descends[1]):
		index1 = descends[0][0]
		index2 = descends[1][0]+1
		finalElem = len(values)-1
		if (values[index1] > values[index2-1]) \
				and ( (index2== finalElem) or ( values[index1] < values[index2+1]) ) :
			if values[index2] < values[index1+1] and \
						(index1==0 or (values[index1-1] < values[index2])):
				print( "yes" )
				print( "swap " + str(index1+1) + " " + str(index2+1))
				exit()

if len( descends ) == 1 :
	# Found one descendign subsequence. Does reversing it work ?
	firstInd = descends[0][0]
	lastInd = descends[0][len(descends[0])-1]+1
	if (firstInd == 0 or (values[firstInd-1] < values[ lastInd ] )) and \
				( (lastInd == len(values)-1) or (values[firstInd] < values[ lastInd+1 ] ) ):
		print( "yes" )
		# We have to swap, if the sequence is only two numbers long
		if lastInd == firstInd+1:
			print( "swap " + str(firstInd+1) + " " + str(lastInd+1) )
		else:
			print("reverse " + str(firstInd + 1) + " " + str(lastInd + 1))
		exit()

print( "no" )
