
//
// https://www.hackerrank.com/challenges/game-of-thrones
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() 
{
	char	c;
	string s;
	cin >> s;
	int		cnt, odd_cnt = 0;

	int flag = 1;

	sort( s.begin() , s.end() );

	// Check count of each letter type.
	for( int i=0 ; i< s.length() ;  ) {
		c = s[i];
		for( cnt=0 ; i<s.length() && s[i]==c ; i++ )
			cnt++;
		if( cnt & 1 ) {
			// Odd letter count
			// We can only have one of those !!
			if( ++odd_cnt > 1 ) {
				flag = 0;
				 break;
			}
		}
	}

    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}


