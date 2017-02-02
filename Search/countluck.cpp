#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <fstream>


/**
 *  Solution for challenge
 *  https://www.hackerrank.com/challenges/count-luck
 */

using namespace std;

class CountLuck {

	int N, M;
	vector< vector< int > > _graph;
	vector< bool > _visited;

	/**
	 Labyrinth describes the area, X-es symbolize walls
	 .X.X......X
	 .X*.X.XXX.X
	 .XX.X.XM...
	 ......XXXX.
	 */
	void createGraph( vector< string > & labyrinth )
	{
		int	row=0, col, pos=0;
		// Take each line
		for( auto & a : labyrinth ) {
			// Check each character
			col = 0;
			for( auto & ch : a ) {
				vector<int> adjacencyList;
				switch( ch ) {
				case '.':
				case '*':
				case 'M':
					// Left ?
					if( col > 0 && a[col-1] != 'X')
						adjacencyList.push_back( pos-1 );
					// Above ?
					if( row > 0 && labyrinth[row-1][col] != 'X')
						adjacencyList.push_back( pos-M );
					// Right ?
					if( col<(M-1) && a[col+1] != 'X' )
						adjacencyList.push_back( pos+1 );
					// Below ?
					if( row < (N-1) && labyrinth[row+1][col] != 'X' )
						adjacencyList.push_back( pos+M );
					break;
				}
				_graph.push_back( adjacencyList );
				col++;
				pos++; // Overall node id
			}
			row++;
		}
	}

	int dfs( int vertex, int start, int finish, int waves )
	{
		_visited[vertex] = true;

		if( vertex == finish )
			return waves;

		if( start == vertex ) {
			if( _graph[vertex].size() > 1 )
				waves++;
		}
		else if( _graph[vertex].size() > 2 )
			waves++;

		for( auto & x : _graph[vertex] ) {
			if( ! _visited[x] ) {
				int r = dfs( x, start,finish,waves);
				if( -1 != r )
					return r; // DONE
			}
		}
		return -1;
	}

	int findPath( int start, int finish )
	{
		_visited.resize( _graph.size(), false );
		int waves = dfs( start, start, finish, 0 );

		return waves;
	}

	void oneTest( istream & inStr )
	{
		int line=0;
		int startPos;
		int finishPos;

		inStr >> N >> M;
		vector< string > matrix;
		_graph.clear();
		_visited.clear();

		for( int n=N ; n > 0 ; n-- ) {
			string l1;
			char ch;
			for( int pos=0 ; pos < M ; pos++ ) {
				inStr >> ch;
				if( 'M' == ch )
					startPos = matrix.size() * M + pos;
				else if( '*' == ch )
					finishPos = matrix.size() * M + pos;
				l1.push_back(ch);
			}
			matrix.push_back( l1 );
		}
		createGraph( matrix );

		int wavesBet;
		inStr >> wavesBet;

		int waves = findPath( startPos, finishPos );
		cout <<  (waves == wavesBet ? "Impressed" : "Oops!") << endl;
	}

public:
	void processAll( istream & inStr )
	{
		int x;

		inStr >> x;
		while( x-- > 0 )
			oneTest( inStr );
	}

};

int main(int arg, char ** argv)
{
	CountLuck  cl;
	//ifstream ifs;
	//ifs.open( argv[1] );
	cl.processAll( cin );
}


