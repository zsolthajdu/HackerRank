
// https://www.hackerrank.com/challenges/camelcase

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
	sort( s.begin(), s.end() );

	auto i = s.begin();
	int  c=0;

	for( ; i!=s.end() && *i<='Z' ; ++i,c++ ) ;
	c++;
	cerr << "Result : " << s << endl;

	cout << c;

	return 0;
}


