// Solution for
// https://www.hackerrank.com/challenges/maxsubarray

#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool myfunction (int i,int j) { return (i>j); }

int main( int argc, char** argv )
{
	auto q = 0;
	auto n = 0;
	ifstream inf;

	inf.open( argv[1], std::ifstream::in );

	inf >> q;
	for( int i=0 ; i<q ; i++ )
	{
		inf >> n;
		vector<int> m;
		int x = 0;

		for( int j=0 ; j<n ; j++ ) {
			inf >> x;
			m.push_back( x );
		}

		auto maxHere = m[0];
		auto maxSoFar = m[0];
		for( int j=1 ; j<n ; j++ ) {
			maxHere  = max( m[j], maxHere + m[j] );
			maxSoFar = max( maxSoFar, maxHere );
		}

		cout << maxSoFar;
		
		// Non continuous

		// Sort in descending order
		sort( m.begin(), m.end(), myfunction );
		auto maxSum = 0;
		if( m[0] < 0 ) {
			// All negatives, just print highes value
			maxSum = m[0];
		}
		else {
			// Sum positive values
			for( auto x: m ) {
				if( x > 0 )
					maxSum += x;
				else
					break;
			}

		}
		cout << " " << maxSum << endl;
	}
	return 0;
}
