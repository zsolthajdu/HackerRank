
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

//
// Solution for
// https://www.hackerrank.com/challenges/bfsshortreach
//

using namespace std;


struct edgenode {
	 int         _y;
	 int         _weight;

	edgenode( int y, int w ) : _y(y), _weight(w){}
};

const int LENGTH  = 6;


class BFS {

	std::vector< std::vector<edgenode> >  _edges;
	int			_nVertices;
	int			_nEdges;
	bool			_directed;
	int		_StartVertex;

	// For traversal.
	// A vertex is discovered the first time we visit it. It is considered processed
	// after we have traversed all outgoing edges from it.
	//bool        _processed[MAXV+1 ];
	std::vector<bool>   _discovered;
	std::vector<int>   _parent;

	void insert_edge( int x, int y, int w = 0 )
	{
		insert_edge( x, y, _directed, w );
	}

	void insert_edge( int x, int y, bool directed, int weight = 0 )
	{
		edgenode Node( y, weight );

		_edges[x].push_back( Node );
		//_degree[x]++;
		if( !directed )
			insert_edge( y, x, true, weight );
		else
			_nEdges++;
	}

public:

	// Breadth First Search
	void bfs( int start )
	{
		std::queue< int > q;
		int v, y;

		q.push( start );
		_discovered[ start ] = true;
		while( ! q.empty() )
		{
			v = q.front();
			q.pop();
			std::vector<edgenode> & e( _edges[v] );
			for( auto p=e.begin() ; p!=e.end() ; ++p )
			{
				y = p->_y;
				if( !_discovered[y] )
				{
					q.push( y );
					_discovered[y] = true;
					_parent[y] = v;
				}
			}
		}
	}

	int find_path( int start, int end )
	{
		if( -1 == end )
			return -1;
	//		throw graph_exception();

		int res = 0;
		if( start == end )
			res = 0;
		else
		{
			res = find_path( start, _parent[end] );
			if( -1 != res )
				res += LENGTH;
		}
		return res;
	}

	void read( std::istream & ifs ) {
		auto	i=0;
		int		edges;

		ifs >> _nVertices;
		ifs >> edges;

		_edges.resize( _nVertices+1 );
		_discovered.resize( _nVertices+1 );
		_parent.resize( _nVertices+1, -1 );

		int  w, x, y;
		for( i=0 ; ifs.good() && (i<edges) ; i++ )	{
			ifs >> x >> y ;
			insert_edge( x, y );
		}

		ifs >> _StartVertex;

	}

	void solution()
	{
		bfs(_StartVertex);
		for( int i=1; i <= _nVertices ; i++ ) {
			if( i != _StartVertex )
				cout << find_path(_StartVertex,i) << " ";
		}
		std::cout << std::endl;
	}

	BFS() : _directed(false) {
	}
};

int main( int argc, const char **argv )
{
	int	n;

	cin >> n;

	while( n-- ) {
		BFS   rtr;

		if( argc > 1 ) {
			// Read from file parameter

			std::ifstream ifs;
			ifs.open( argv[1] , std::ifstream::in );
			if( !ifs.good() )
				return 0;
			rtr.read( ifs );
		}
		else
			rtr.read( cin );

		rtr.solution();
	}
}
