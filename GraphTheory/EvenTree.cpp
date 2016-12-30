//
// https://www.hackerrank.com/challenges/even-tree

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int CHARMAX = 128;

struct edgenode {
    int         _y;
    int         _weight;

	edgenode( int y, int w ) : _y(y), _weight(w){}
};

const int MAXV  = 1000;
const int ROOTVERT = 1;

class EvenTree
{
	std::vector< std::vector<edgenode> >  _edges;
	int			_nVertices;
	int			_nEdges;
	bool			_directed;

	// For traversal.
	// A vertex is discovered the first time we visit it. It is considered processed
	// after we have traversed all outgoing adges from it.
	bool        _processed[MAXV+1 ];
	bool        _discovered[ MAXV+1 ];
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

	EvenTree() : _nVertices(0), _nEdges(0), _directed(false)
	{
		_vCount = _delCount = 0;
		_hadOdd = false;
	}

	//
	// Reader from stdin
	//
	void read()
	{
		auto	cEdges=0, i=0;

		cin >> _nVertices;
		cin >> cEdges;

		_edges.resize( _nVertices+1 );
		_parent.resize( _nVertices+1, -1 );

		int x, y;
		for( i=1 ; i<=cEdges ; i++ )	{
			cin >> x >> y;
			insert_edge( x, y );
		}

		for( i=1 ; i<= _nVertices ; i++ )
			_discovered[i] = false;
	}

	//
	// Reads input from a file
	void read( const char* fname, bool weighted = false )
	{
		std::ifstream ifs;
		auto	cEdges=0, i=0;

		ifs.open( fname , std::ifstream::in );
		if( !ifs.good() )
			return;

		ifs >> _nVertices;
		ifs >> cEdges;

		_edges.resize( _nVertices+1 );
		_parent.resize( _nVertices+1, -1 );

		if( weighted ) {
			int  w, x, y;
			for( i=1 ; ifs.good() && ( i<=cEdges ) ; i++ )	{
				ifs >> x >> y >> w;
				insert_edge( x, y, w );
			}
		}
		else {
			int x, y;
			for( i=1 ; ifs.good() && ( i<=cEdges ) ; i++ )	{
				ifs >> x >> y;
				insert_edge( x, y );
			}
		}

		for( i=1 ; i<= _nVertices ; i++ )
			_discovered[i] = false;
	}

	int	_vCount;
	bool  _hadOdd;
	int	_delCount;

	// Do depth first search
	int search( int v )
	{
		int     y;
		int res = 1; // count node 'v'

		_discovered[v] = true;

		std::vector<edgenode> & e( _edges[v] );
		for( auto p=e.begin() ; p!=e.end() ; ++p )
		{
			y = p->_y;
			if( !_discovered[y] )
			{
				_parent[y] = v;
				res += search( y ); // add children
			}
		}

		// After checking kids
		if( v != ROOTVERT )
			if( res>0 && (res % 2) == 0 ) {
				_delCount++;
				res = 0;
			}

		return res;
	}

	int getDelCnt() { return _delCount; }

};

int main( int argc, char **argv )
{
	EvenTree et;

	et.read( argv[1] );
	et.search(1);
	cout << et.getDelCnt() << endl;

	return 0;
}
