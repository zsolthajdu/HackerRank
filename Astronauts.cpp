
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
    auto nAstronauts = 0, nPairs = 0;
	ifstream inf;

	inf.open(argv[1], ifstream::in);

	inf >> nAstronauts >> nPairs;
	
	vector<vector<int> > lists(nAstronauts);
	vector< set<int> > countries;

	for (int i = 0; i < nPairs; ++i) {
        int a, b;
        inf >> a >> b;
        lists[a].push_back(b);
        lists[b].push_back(a);
	}

	if( lists.empty() ) {
		cout << 0 << endl;
		return 0;
	}

	queue< int > q;
	int currAstr = 0;

	// Sort astronauts into sets
	// representing countries
	for( const auto & ai : lists ) {
		set< int > country;

		if( !ai.empty() ) {
			q.push( currAstr );
			country.insert( currAstr );
			while( !q.empty() ) {
				auto x = q.front();
				q.pop();

				if( !lists[x].empty() ) {
					for( auto & a : lists[x] ) {
						q.push( a );
						country.insert( a );
					}
					lists[x].clear();
				}
			}
			countries.push_back( country );
		}
		currAstr++;
	}

	long long pairedAstronauts = 0;
	// Add up sizes of each country vectors. This will be the number
	// of astronauts from countries with more than one astronaut
	for( const auto & country : countries )
		pairedAstronauts += country.size();

	// There may be countries with just one astronaut
	long long loneAstronauts = nAstronauts - pairedAstronauts;

	long long result = 0;

	// This is pairs from countries with multiple astronauts
	for( auto c=0 ; c<countries.size()-1 ; c++ ) {
		 int nMen = countries[c].size();
		 for( auto j = c+1; j < countries.size() ; j++ )
			 result += nMen * countries[j].size();
	}

	// Accounting for countries with single astronauts
	if( loneAstronauts > 0 ) {
		// cerr << "There are " << loneAstronauts << " lone astronauts." << endl;
		// Pairs of lone astronauts with regular countries' astronauts
		for( const auto & country : countries )
			result += loneAstronauts * country.size();

		// Pairs of LONE astronauts amongst themselves
		result += loneAstronauts * (loneAstronauts-1)  / 2;
	}

	cout << result << endl;
	return 0;
}
