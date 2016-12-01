
struct node
{
	 int data;
	 node * left;
	 node * right;
}node;

node * insert(node * root, int value)
{
	if( 0 == root ) {
		node * p = new node();
		p->data = value;
		p->left = p->right = 0;
		return p;
	}

	if( value < root->data ) {
		if( 0 == root->left ) {
			node * p = new node();
			p->data = value;
			p->left = p->right = 0;
			root->left = p;

		}
		else
			insert( root->left, value );
	}
	else {
		if( 0 == root->right ) {
			node * p = new node();
			p->data = value;
			p->left = p->right = 0;
			root->right = p;
		}
		else
			insert( root->right, value );
	}

	return root;
}

