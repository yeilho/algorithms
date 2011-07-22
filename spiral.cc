// printing a matrix sprially from outside to inside
#include <iostream>

using namespace std;
#define N 5
#define M 5

void spiral(int map[][M], int n, int m)
{
	int i;
	int left = 0, right = n, up = 0, down = m;
	
	while (1) {
		if (left == right) break;
		for (i = left; i < right; i++)
			cout << map[i][up] << " ";
		
		if (up+1 == down) break;
		for (i = up+1; i < down; i++)
			cout << map[right-1][i] << " ";

		if (right-2 < left) break;
		for (i = right-2; i >= left; i--)
			cout << map[i][down-1] << " ";

		if (down-2 == up) break;
		for (i = down-2; i > up; i--)
			cout << map[left][i] << " ";
		
		left++; right--;
		up++; down--;
	}

	cout << endl;
}

int main(int argc, char *argv[])
{
	int count = 0;
	int map[N][M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = count++;
			cout << map[i][j] << " ";
		}
	}
	cout << endl;

	spiral(map, N, M);

	return 0;
}