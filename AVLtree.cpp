
#include <algorithm>

using namespace std;

// https://www.hackerrank.com/challenges/self-balancing-tree
// AVL tree insert implementation
//
// Based on explanation: http://www.geeksforgeeks.org/avl-tree-set-1-insertion/
//

struct node
{
	int val;            //value
	struct node* left;  //left child
	struct node* right; //right child
	int ht;             //height of the node
};


int height( node* n )
{
	// Return -1 for nullptr to pass test cases
	return nullptr == n ? 0 : n->ht;
}

node * rotateLeft( node * n )
{
	node* rightNode = n->right;
	n->right = rightNode->left;
	rightNode->left = n;

	// Update heights
	n->ht = max( height(n->left), height(n->right)) + 1;
	rightNode->ht = max( height(rightNode->left), height(rightNode->right)) + 1;
	return rightNode;
}

node * rotateRight( node * n )
{
	node * leftNode = n->left;
	n->left = leftNode->right;
	leftNode->right = n;

	n->ht = max( height(n->left), height(n->right)) + 1;
	leftNode->ht = max( height(leftNode->left), height(leftNode->right)) + 1;
	return leftNode;
}

node* createNode( int val )
{
	node* newnode = new node();
	newnode->val = val;
	newnode->ht = 1; // SHould be 0 to pass test cases !!
	newnode->left = newnode->right = 0;
	return newnode;
}

node *insert(node * root,int val)
{
	if( nullptr == root )
		return createNode( val );
	else {
		if( val < root->val )
			root->left = insert( root->left, val );
		else
			root->right = insert( root->right, val );
	}

	root->ht = max( height(root->left), height(root->right)) + 1;

	// Difference of heights between Left/Right children
	// aka balance factor
	int hDiff = height(root->left) - height(root->right);

	// There are 4 possible scenarios
	if( hDiff > 1 && val < root->left->val )
		// Left Left case
		return rotateRight( root );

	if( hDiff < -1 && val > root->right->val )
		// Right right case
		return rotateLeft( root );

	if( hDiff > 1 && val > root->left->val ) {
		// Left Right case
		root->left = rotateLeft( root->left );
		return rotateRight( root );
	}

	if( hDiff < -1 && val < root->right->val ) {
		// Right Left case
		root->right = rotateRight( root->right );
		return rotateLeft( root );
	}

	return root;
}

int main( int argc, char** argv )
{
	int N, I;
	//ifstream inf;
	//inf.open(argv[1], ifstream::in);

	node* root = insert( nullptr, 3 );
	root = insert( root, 2 );
	root = insert( root, 4 );
	root = insert( root, 5 );
	root = insert( root, 6 );
}
