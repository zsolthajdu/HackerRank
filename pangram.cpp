#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int op_tolower( char c ) { return tolower(c); }

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    getline( cin, s );
    set< char > alphabet;

    transform( s.begin(), s.end(), s.begin(), op_tolower );
    int i;

	
    for(i=0 ; i<s.size() ; i++ ) {
        if( ' ' != s.at(i) ) {
            alphabet.insert( s.at(i) );
        }
    }
    cerr << "String len : " << s.size() << " Alph size " << alphabet.size() << endl;
    if( 26 == alphabet.size() )
        cout << "pangram" << endl;
    else
        cout << "not pangram" << endl;        
    
    return 0;
}

