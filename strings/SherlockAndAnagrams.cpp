//
// https://www.hackerrank.com/challenges/sherlock-and-anagrams

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int CHARMAX = 128;

class AnagramFinder
{
	int _subStrCnt[ CHARMAX ];
	int _strCnt[ CHARMAX ];

	int countLetters( const char* str, int len, int* cntStore ) {
		memset( cntStore, 0, sizeof(int) * CHARMAX );

		//
		for( int i=0 ; i<len ; i++ )
			cntStore[ str[i]]++;

		return 0;
	}

public:

	int process( const char* line ) {
		int	len, x;
		int	nAnagrams = 0;

		for( len=1 ; len <= strlen( line )-1 ; len++ ) {

			// Look at every substring len length
			for( int s=0 ;  s<= (strlen(line)-len) ; s++ ) {
				countLetters( line+s, len, _subStrCnt );

				// Then check for anagrams in the rest of the string
				for( int t=0 ;  t<= (strlen(line)-len) ; t++ ) {
					if( s == t )
						continue; // skip original location

					countLetters( line+t, len, _strCnt );

					for( x=0 ; x<CHARMAX ; x++ ) {
						if( _strCnt[x] != _subStrCnt[x] )
							break;
					}
					if( x == CHARMAX ) {
						// Found match
						nAnagrams++;
					}
				}
			}
		}
		return nAnagrams / 2;
	}
};

int main()
{
	string line;
	auto n = 0;
	AnagramFinder af;

	cin >> n;
	for( int i=0 ; i<n ; i++ )
	{
		cin >> line;

		int c = af.process( line.c_str() );

		cout << c << endl;
	}
	return 0;
}
