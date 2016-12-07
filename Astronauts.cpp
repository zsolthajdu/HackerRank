
// https://www.hackerrank.com/challenges/journey-to-the-moon
// solution

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;

//
// Az atro2.txt teszt adatra a jo eredmeny : 4999949998
//

int main( int argc, char** argv )
{ 
    int N, I;
	ifstream inf;

	inf.open(argv[1], ifstream::in);

	inf >> N >> I;
	
	int	c;

	vector<vector<int> > pairs(N);
	vector< set<int> > countries;

	for (int i = 0; i < I; ++i) {
        int a, b;
        inf >> a >> b;
		  pairs[a].push_back(b);
		  pairs[b].push_back(a);
	}

	if( pairs.empty() ) {
		cout << 0 << endl;
		return 0;
	}

	vector<vector<int> >::iterator ai;
	queue< int > q;
	int currAstr = 0;
	long long loneAstronauts = 0;

	// Sort astronauts into sets
	// representing countries
	for( ai=pairs.begin() ; ai != pairs.end() ; ++ai, currAstr++ ) {
		set< int > country;
		int x = 0;

		if( ai->size() != 0 ) {
			//if( ai->at(0) == -1 )
			//	continue;
			q.push( currAstr );
			country.insert( currAstr );
			while( !q.empty() ) {
				x = q.front();
				q.pop();

				if( pairs[x].empty() )// || -1==pairs[x].at(0) )
					continue;
				int j;
				for( j=0 ; j<pairs[x].size() ; j++ ) {
					q.push( pairs[x].at(j) );
					country.insert( pairs[x].at(j) );
				}
				pairs[x].clear();
				//pairs[x].push_back(-1);
			}
			countries.push_back( country );
		}
	}

	long long allAst = 0;
	for( c = 0 ; c< countries.size() ; c++ )
		allAst += countries[c].size();

	loneAstronauts = N - allAst;

	long long result = 0;

	/** Write code to compute the result using N,I,pairs **/

	// This is pairs from coutnries with multiple astronauts
	for( c=0 ; c<countries.size()-1 ; c++ ) {
		 int nMen = countries[c].size();
		 for( int j = c+1; j < countries.size() ; j++ )
			 result += nMen * countries[j].size();
	}

	// Accounting for countries with single astronauts
	if( loneAstronauts > 0 ) {
		// cerr << "There are " << loneAstronauts << " lone astronauts." << endl;
		// Pairs of lone astronauts with regular countries' astronauts
		for( c=0 ; c<countries.size() ; c++ )
			result += loneAstronauts*countries[c].size();

		// Pairs of LONE astronauts amongst themselves
		result += loneAstronauts * (loneAstronauts-1)  / 2;
	}

	cout << result << endl;
	return 0;
}
