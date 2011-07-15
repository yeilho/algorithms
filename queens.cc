// 8-Queen problem
#include <iostream>

using namespace std;

#define N 8
int queens[N];

int valid(int x, int y)
{
	int i;
	// row
	for (i = 0; i < x; i++) {
		if (queens[i] == y)
			return 0;
	}
	for (i = 0; i < x; i++) {
		// major-diagonal
		if ((y-queens[i]) == (x-i))
			return 0;
		// minor diagonal
		if ((queens[i]-y) == (x-i))
			return 0;
	}
	return 1;
}

int chess(int n)
{
	int ways = 0;
	for (int i = 0; i < N; i++) {
		if (valid(n, i)) {
			queens[n] = i;
			if (n == 7) {
				return 1;
			} else {
				ways += chess(n+1);
			}
		}
	}
    return ways;
}

int main(int argc, char *argv[])
{
	for (int i = 0; i < N; i++)
		queens[i] = -1;
	cout << chess(0) << endl;
	return 0;
}