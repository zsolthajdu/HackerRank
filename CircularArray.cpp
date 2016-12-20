
//
// https://www.hackerrank.com/challenges/circular-array-rotation

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
	int	n, k, q;

	cin >> n >> k >> q;

	k = k%n;

	vector<int>	v{ n, 0 };

	for( int i=k ; i<n ; i++ ) 
		cin >> v[i];
	
	for( int i=0 ; i<k ; i++ ) 
		cin >> v[i];

	for( int i=0 ; i<q ; i++ )  {
		int a;
		cin >> a;
		cout << v[a] << endl;
	}

	return 0;
}

