// Solution for 'Flipping the Matrix'
// https://www.hackerrank.com/challenges/flipping-the-matrix

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	auto q = 0;
	auto n = 0;

	cin >> q;
	for( int i=0 ; i<q ; i++ )
	{
		cin >> n;
		vector<int> m;
		int x = 0;

		for( int j=0 ; j<4*n*n ; j++ ) {
			cin >> x;
			m.push_back( x );
		}

		auto sum = 0;
		auto full = 2*n;

		//
		// For each position in the top-left quadrant we have to check
		// the corresponding (mirrored) values in the other 3 quadrants
		// and simply find the highest value.
		// The max sum in the top left quadrant is the collection (sum)
		// of those maximums.
		//
		for( int a=0 ; a<n ; a++ ) { // rows in top left quadrant
			int cMax = 0, t;
			for( int b=0 ; b<n ; b++ ) { // columns in t/l quadrant
				cMax = m.at( full*a + b ); // T/L value;

				t = m.at( full*a + (full-1-b) );
				if( t > cMax ) // Value in mirrored postion in
					cMax = t;  // the top/right quadrant

				t = m.at( full * (full-1-a) + b );
				if( t > cMax ) // Same in bottom/left
					cMax = t;

				t = m.at( full * (full-1-a) + full-1-b );
				if( t > cMax )
					cMax = t;   // Same bottom-right

				sum += cMax;
			}
		}

		cout << sum << endl;
	}
	return 0;
}
