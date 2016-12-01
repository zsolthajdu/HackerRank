
//
//  https://www.hackerrank.com/challenges/tree-huffman-decoding
//

//The structure of the node is

typedef struct node
{
	 int freq;
	 char data;
	 node * left;
	 node * right;

}node;




void decode_huff(node * root,string s)
{
	node * currNode = root;
	int   p;
	bool	done;

	if( 0 == root )
		return;

	for( p=0 ; p<s.size() ; ) {
		done = false;
		currNode = root;

		while( false==done && p<s.size() )
		{
			int n = s[p++] - '0';
			if( 1 == n ) {
				currNode = currNode->right;
				if( currNode->right == 0 && currNode->left == 0 ) {
					cout << currNode->data;
					done = true;
				}
			}
			else {
				currNode = currNode->left;
				if( currNode->right == 0 && currNode->left == 0 ) {
					cout << currNode->data;
					done = true;
				}
			}
		}
	}
}
