
//
//  https://www.hackerrank.com/challenges/gridland-metro
//


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char **argv )
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int  n, m, a, r, start, end, i;
	 long long	sum;
	 ifstream ifs;
	 ifs.open( argv[1], std::ifstream::in );

    ifs >> n;
    ifs >> m;
    ifs >> a;
    map< int, vector<int> > lefts;
    map< int, vector<int> > rights;
    map< int, vector<int> > ::iterator li;
    map< int, vector<int> > ::iterator ri;
    
    sum = (long long)n * m;
    if( 0 == sum )   {
        cout << 0 << endl;
        return 0;
    }
    
    for( i = 0 ; i<a ; i++ ) {
        ifs >> r;
        ifs >> start;
        ifs >> end;

        lefts[r].push_back( start );
        rights[r].push_back( end );
    }

    for( li = lefts.begin() , ri = rights.begin() ; li != lefts.end() ; ++li, ++ri ) {
        sort( li->second.begin(), li->second.end() );
        sort( ri->second.begin(), ri->second.end() );
        int curleft, curright;
        for( i=0 ; i<li->second.size() ;) {
            curleft = li->second[i];
            curright = ri->second[i++];

            while( i<li->second.size() && li->second[i] <= curright )
                curright = ri->second[i++];
  
            // Found one continous section
            sum -= curright-curleft+1;
        }
    }

    cout << sum << endl;
    return 0;
}


