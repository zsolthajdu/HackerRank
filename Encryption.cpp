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
#include <cassert>

// Solution for
// https://www.hackerrank.com/challenges/encryption

using namespace std;

int op_tolower( char c ) { return tolower(c); }

bool myfunction (int i,int j) { return (i>j); }
int op_increase (int i) { return ++i; }

class encryptor
{

public:
	string process(string& s)
	{
		string a;

		for (int i = 0; i < s.length(); i++)
		{
			if (' ' != s.at(i))
				a.push_back(s[i]);
		}
		string result;

		int c, r;
		auto l1 = sqrt(a.length());
		r = floor( l1 );
		c = ceil(l1);
		assert(r*c >= a.length());

		cout << c << " x " << r << " raster" << endl;

		for (int i = 0; i < c; i++) {
			// add next column
			int j = i;
			while( j < a.length()) {
				result.push_back(a.at(j));
				j += c;
			}
			result.push_back(' ');
		}

		return result;
	}
};

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	string sentence{ "if man was meant to stay on the ground god would have given us roots" };

	//cin >> sentence;
	
	encryptor e;

	auto outStr{ e.process(sentence) };

	cout << outStr;

    return 0;
}

