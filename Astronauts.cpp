
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

using namespace std; // }}}
 
int main( int argc, char** argv )
{ 
    int N, I;
	ifstream inf;

	inf.open(argv[1], ifstream::in);

    inf >> N >> I;
	
	vector< set< int > > all;
	int	setA = -1, setB = -1, i, c;

    //vector<vector<int> > pairs(N);

	for (int i = 0; i < I; ++i) {
        int a, b;
        inf >> a >> b;
		setA = -1; setB = -1;
    //    pairs[a].push_back(b);
    //    pairs[b].push_back(a);
	
		for( c=0 ; c<all.size() && ( -1==setA || -1==setB ) ; c++ ) {
			set<int>::iterator aa = all[c].find( a );
			if( all[c].end() != aa ) {
				setA = c;
			}
            aa = all[c].find( b );
			if( all[c].end() != aa ) {
				setB = c;
			}
		}
			
		if( -1==setA && -1==setB ) {
			set<int> nn;
			nn.insert( a );
			nn.insert( b );
			all.push_back( nn );
		}
		else if( -1 != setA && -1!=setB ) {
			if( setA != setB ) {
				set<int>::iterator xx;
				for( xx=all[setB].begin() ; xx!=all[setB].end() ; ++xx )
					all[setA].insert( *xx );
				all.erase( all.begin() + setB );
			}
		}
		else if( -1 == setA ) {
			all[setB].insert( a );
		}
		else if( -1 == setB )
			all[setA].insert( b );
	}
	
	long long allAst = 0;
	for( c = 0 ; c< all.size() ; c++ )
		allAst += all[c].size();
	for( ; allAst < N ; allAst++ ) {
		set<int> ss;
		ss.insert(0);
		all.push_back( ss );
	}
	
    long long result = 0;
    
    /** Write code to compute the result using N,I,pairs **/
   for( int c=0 ; c<all.size()-1 ; c++ ) {
	   int nMen = all[c].size();
	   for( int j = c+1; j < all.size() ; j++ ) {
		   result += nMen * all[j].size();
	   }
   }    
 
    cout << result << endl;
    return 0;
}
