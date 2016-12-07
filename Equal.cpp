#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <vector>

// Solution for
// https://www.hackerrank.com/challenges/equal

using namespace std;

int op_tolower( char c ) { return tolower(c); }

bool myfunction (int i,int j) { return (i>j); }
int op_increase (int i) { return ++i; }

typedef vector<int> vec;

int countSteps( vec & v, int step )
{
	int res = 0;

	vec::iterator x;

	for( x=v.begin() ; x!=v.end()  ; ++x ) {
		while( *x >= step ) {
			*x -= step;
			res++;
		}
	}
	return res;
}


int calcRound( vector<int> & v )
{
	vec a( v );
	vec diffs( v );
	vec b;
	auto cnt = 0, cnt2 = 0;

	sort( a.begin(), a.end() );
	cerr << "Smallest item : " << a[0] << endl;

	vector<int>::iterator i;

	for( i=diffs.begin() ; i != diffs.end() ; ++i ) {
		*i -= a[0];
	}

	a = diffs;
	b = v;
	// Sort in descending order
	sort( diffs.begin(), diffs.end(), myfunction );

	cnt += countSteps( diffs, 5 );
	cnt += countSteps( diffs, 2 );
	cnt += countSteps( diffs, 1 );

	// Same for one larger diffrences
	transform( a.begin(), a.end(), a.begin(), op_increase );
	cnt2 += countSteps( a, 5 );
	cnt2 += countSteps( a, 2 );
	cnt2 += countSteps( a, 1 );

	cnt = min<int>( cnt, cnt2 );

	cnt2 = 0;
	cnt2 += countSteps( b, 5 );
	cnt2 += countSteps( b, 2 );
	cnt2 += countSteps( b, 1 );

	return min<int>( cnt, cnt2 );
}

void OneCase()
{
	int		numbers, v;
	vector<int>	mults;
	vector<int>	values;

	cin >> numbers;

	for( int i = 0 ; i<numbers ; i++ ) {
		cin >> v;
		values.push_back( v );
	}

	int n = calcRound( values );
	cout << n << endl;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
	 int cases;

	 cin >> cases;
	 for( int a=0 ; a<cases ; a++ )
		 OneCase();

    return 0;
}

