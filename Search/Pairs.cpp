
#include <vector>
#include <set>
#include <algorithm>


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

	for (auto & x : a) {
		if (items.find(x + k) != items.end())
			ans++;
	}
	return ans;
}

int main(int arg, char ** argv)
{

	vector<int> test1{ 1,5,3,4,2 };

	pairs(test1, 2);
}
