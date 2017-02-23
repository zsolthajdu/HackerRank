#!/usr/bin/python3

import sys
import math
from collections import deque

# Solution for
# https://www.hackerrank.com/challenges/cut-the-tree

class Node:
	def __init__(self, key, value):
		self.val = value
		self.key = key
		self.children = []

	def addChild(self, n):
		self.children.append(n)

	def sumChildren(self, tree):
		for c in range(len(self.children)):
			self.val += tree[ self.children[c] ].val

	# Add Node's children keys to list
	def addChildren(self, outList):
		for c in range(len(self.children)):
			outList.append(self.children[c])

	def findCutLocation(self, tree ):
		minDiff = 10000000000;
		fullSum = tree[1].val
		for a in range(1,len(tree)):
			# Check differences
			for c in range(len(tree[a].children)):
				child = tree[a].children[c]
				top = fullSum - tree[child].val
				diff = abs( top - tree[child].val )
				if diff == 0:
					return 0
				if diff < minDiff:
					minDiff = diff
		return minDiff

class Tree:
	def __init__(self, nodeValues):
		self.tree = []
		# tree[0] not used. First vertex is '1'
		self.tree.append( Node( 0, 0 ) )
		for i in range(V):
			self.tree.append( Node(i+1, nodeValues[i] ))

	def getTree(self):
		return self.tree

	# DFS traversal to update each Node value field to include
	# the sum of all child values
	def sumAllSubtrees(self):
		visited = [ False for i in range( len(self.tree)+1 ) ]
		stack = [1]
		while len(stack) > 0:
			v = stack[ len(stack)-1 ]
			if False == visited[v]:
				visited[v] = True
				self.tree[v].addChildren( stack )
			else:
				stack.pop()
				self.tree[v].sumChildren( self.tree )

	def findCutLocation(self, start ):
		return self.tree[start].findCutLocation( self.tree)

class AdjacencyList:
	def __init__(self, nVert):
		self.adjList = []
		self.nVertices = nVert

	# Reads vertex pairs from standard input
	def build( self ):
		self.adjList.append( [] )
		while True:
			try:
				# Read two vertex numbers
				v,w = map( int, input().split() )
				# Extend list
				m = max( v, w )
				while len( self.adjList ) <= m:
					self.adjList.append( [] );
				# Add new edges to adjacency list
				self.adjList[v].append( w )
				self.adjList[w].append(v)
			except EOFError:
				break;

	# BFS traversal to create a tree of nodes from
	# adjacency lists
	def createTree(self, root, tree):
		queue = deque( [ root ] )
		visited = [ False for i in range( self.nVertices+1 ) ]
		while len( queue) > 0 :
			v = queue.popleft()
			visited[v] = True
			for j in range(len(self.adjList[v])):
				child = self.adjList[v][j]
				if False == visited[child]:
					tree[v].addChild(child)
					queue.append( child )

V = int( input() )
al = AdjacencyList( V )

# Read n integers, the node Values
lst = list( map(int, input().split(' ')))
if len(lst) != V:
	print( "Not enough data !!\n" )
	exit

tree = Tree( lst )
al.build()
al.createTree( 1, tree.getTree() )
tree.sumAllSubtrees()
print( tree.findCutLocation( 1 ) )

