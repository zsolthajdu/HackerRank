
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <vector>

// Solution for
// https://www.hackerrank.com/challenges/richie-rich

// Test 1
// 5 1
// 12321
// output : 12921

// 6 3
// 932239
// Output : 992299

using namespace std;

class Richie
{
	int n, k;
	string number;

public:
	int process()
	{
		queue<int> diffs; // char positions in number, that differs from pair
		auto i=0;
		auto changes = 0;

		for(i=0; i < n/2 ; i++ ) {
			if( number[i] != number[n-1-i] )
				diffs.push( i );
		}
		cerr << diffs.size() << " differences" << endl;

		if( diffs.empty() && 0==k )
			cout << number << endl;
		else if( !diffs.empty() && (k < diffs.size() ) )
			cout << "-1" << endl;
		else {
			if( diffs.size() < k ) {
				if( diffs.empty() ) {
					// Already a palindrome. Try to increase value by changing pairs
					// to 9s.
					for( i=0 ; i<(n/2) ; i++) {
						// Mirror values. Change to 9 if not already
						if( '9' != number[i] && (k>1) ) {
							number[i] = '9';
							number[n-1-i] = '9';
							k-=2;
							changes++;
						}
					}
				}
				else
					for( i=0 ; i<(n/2) && k > diffs.size(); i++) {
						if( i == diffs.front() ) {
							// Difference pos
							if( number[i] != '9' ) {
								number[i] = '9';
								k--;
								changes++;
							}
							if( number[n-1-i] != '9' ) {
								number[n-1-i] = '9';
								k--;
								changes++;
							}
							diffs.pop();
						}
						else {
							// Mirror values. Change to 9 if not already
							if( '9' != number[i] && (k>1) ) {
								number[i] = '9';
								number[n-1-i] = '9';
								k-=2;
								changes++;
							}
						}
					}
			}
			// Make rest of exchanges
			while( !diffs.empty() ) {

				auto x = diffs.front();
				if( number[ x ] == number[ n-1-x ] )
					continue;
				if( number[ x ] > number[ n-1-x ] )
					number[ n-1-x ] = number[x];
				else
					number[x] = number[n-1-x];
				diffs.pop();
				k--;
				changes++;
			}
			if( k>0 && (n&1 == 1 ) ) {
				// Still have changes, try middle one
				if( number[ n/2 ] != '9' ) {
					number[n/2] = '9';
					changes++;
				}
			}
			cout << (0==changes ? "-1" : number) << endl;
		}
		return 0;
	}

	Richie( int a, int b, string &x ) : n(a), k(b), number(x)
	{

	}
};

int main(int argc, char **argv )
{
	int n, k;
	 string number;
	 ifstream  ifs;
	 ifs.open( argv[1], std::ifstream::in );
	
//    cin >> n >> k;
//    cin >> number;
	 ifs >> n >> k;
	 ifs >> number;

	Richie rich( n,k,number );
	rich.process();

	return 0;
}

