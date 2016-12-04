
// Solution for :
// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor
// 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;



node * lca(node * root, int v1,int v2)
{
	node * curr = root;
	while( true ) {
		if( v1 == curr->data || v2 == curr->data )
		     return curr;
		if( (v1 < curr->data && v2 > curr->data ) ||  (v1 > curr->data && v2 < curr->data) )
			return curr;
		if( v1 < curr->data )
			curr = curr->left;
		else
			curr = curr->right;
	}
}



