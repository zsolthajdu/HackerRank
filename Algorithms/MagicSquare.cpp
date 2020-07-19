
//
// https://www.hackerrank.com/challenges/magic-square-forming/problem
//

#include <array>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <deque>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <limits>
#include <vector>
#include <numeric>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class MagicSquare
{
	const int  size_ = 3;
	int	 vals_[12][9];

	// Create original in index [0]
	void create()
	{
		memset(vals_[0], 0, sizeof(vals_[0]));
		int n = 1;

		int x = 1, y = 0;
		while (n < 10) {
			vals_[0][y * size_ + x] = n++;
			int xNext = (x + 1) % size_, yNext = y==0 ? size_-1 : y-1;
			if (0 != vals_[0][yNext * size_ + xNext])
				y++;  // Already taken
			else {
				x = xNext;
				y = yNext;
			}
		}
	}

	void rotateCW(int* src, int* dst )
	{
		for (int r = 0; r < size_; r++) {
			int* dstCol = &dst[size_-r-1];
			int* srcRow = &src[r * size_];
			// Source row to dst column
			for (int c = 0; c < size_; c++)
				*(dstCol + c*size_ ) = srcRow[c];
		}
	}

	// Copy source square, but mirrored over horizontal middle row
	void mirrorHorizontal(int* src, int* dst)
	{
		for (int r = 0; r < size_; r++) // rows
			memcpy(&dst[size_ * (size_-r-1)], &src[size_ * r], sizeof(int)*size_);
	}

	// Copy source square, but mirrored over vertical middle row
	void mirrorVertical(int* src, int* dst)
	{
		for (int r = 0; r < size_; r++) {
			int* dstRow = &dst[r * size_]; 
			int* srcRow = &src[r * size_];
			for (int c = 0; c < size_; c++) // columns
				dstRow[size_ - c - 1] = srcRow[c];
		}
	}

	int compareSquares(int* sqOne, int* sqTwo)
	{
		int diff = 0;

		for (int i = 0; i < size_ * size_; i++)
			diff += abs(*sqOne++ - *sqTwo++);
		return diff;
	}

public:
	MagicSquare()
	{
		create(); // at [0]
		// Generate mirrored variants
		mirrorVertical(vals_[0], vals_[1]);
		mirrorHorizontal(vals_[0], vals_[2]);

		rotateCW(vals_[0], vals_[3]);
		// Generate mirrored variants
		mirrorVertical(vals_[3], vals_[4]);
		mirrorHorizontal(vals_[3], vals_[5]);

		rotateCW(vals_[3], vals_[6]);
		// Generate mirrored variants
		mirrorVertical(vals_[6], vals_[7]);
		mirrorHorizontal(vals_[6], vals_[8]);

		rotateCW(vals_[6], vals_[9]);
		// Generate mirrored variants
		mirrorVertical(vals_[9], vals_[10]);
		mirrorHorizontal(vals_[9], vals_[11]);
	}

	void print(int x)
	{
		cout << vals_[x][0] << " " << vals_[x][1] << " " << vals_[x][2] << endl;
		cout << vals_[x][3] << " " << vals_[x][4] << " " << vals_[x][5] << endl;
		cout << vals_[x][6] << " " << vals_[x][7] << " " << vals_[x][8] << endl;
	}

	// Compare incoming square against all stored squares and
	// return the smalles difference value
	int smallestDifference( int * square )
	{
		int res = 10000;
		for (auto v = 0; v < 12; v++) {
			int c = compareSquares(vals_[v], square);
			if (c < res)
				res = c;
		}
		return res;
	}

	int smallestDifference(vector< vector<int> > s)
	{
		int tmp[9], c = 0;

		for (int i = 0; i < size_; i++) {
			for (int j = 0; j < size_; j++) {
				tmp[c++] = s[i][j];
			}
		}
		return smallestDifference(tmp);
	}
};

int main()
{
	MagicSquare ms;

	//ms.print(0);
	//cout << endl;
	//ms.print(3);

	vector< vector<int> > a{ {5,3,4}, {1,5,8}, {6,4,2 } };
	int smallestDiff = ms.smallestDifference(a);
	cout << "Diff = " << smallestDiff << endl;

	int  s[] = { 5,3,4,1,5,8,6,4,2 };
	smallestDiff = ms.smallestDifference( s );
	cout << "Diff = " << smallestDiff << endl;
	
	int  t[] = { 4,9,2,3,5,7,8,1,5 };
	smallestDiff = ms.smallestDifference(t);
	cout << "Diff = " << smallestDiff << endl;
	
	int  u[] = { 4,8,2,4,5,7,6,1,6 };
	smallestDiff = ms.smallestDifference(u);
	cout << "Diff = " << smallestDiff << endl;

	return 0;
}


