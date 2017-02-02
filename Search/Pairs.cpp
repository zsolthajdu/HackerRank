
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>


/*
  Solution for
  https://www.hackerrank.com/challenges/pairs
  Count the number of pairs of integers whose difference is 'k'

*/

using namespace std;

int pairs(vector < int > a, int k) 
{
	int ans = 0;
	set<int> items;

	for (auto & x : a)
		items.insert(x);

	// Go through values
	for (auto & x : a) {
		// Check if 'x+k' also exists in vector
		if (items.find(x + k) != items.end())
			ans++;
	}
	return ans;
}

int main(int arg, char ** argv)
{
	// Test vector
	vector<int> test1{ 1,5,3,4,2 };

	cout << "Found " << pairs(test1, 2) << " pairs.\n";
}
