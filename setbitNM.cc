#include <iostream>
#include <windows.h>

using namespace std;

#define setbit(N, i) (N |= (1 << i))
#define clearbit(N, i) (N &= ~(1 << i))
#define testbit(N, i) (N & (1 << i))
#define getbit(N, i) ((N >> i) & 0x1)

int setNM(int n, int m, int i, int j)
{
    int k;
    for (k = 0; k < j-i+1; k++) {
        if (m & 0x1) {
            setbit(n, k+i);
        } else {
            clearbit(n, k+i);
        }
        m = m >> 1;
    }
    return n;
}

int main(int argc, char *argv[])
{
    int n, m, result;
    int i, j;

    cout << "enter N: ";
    cin >> n;
    cout << "enter M: ";
    cin >> m;
    cout << "enter i: ";
    cin >> i;
    cout << "enter j: ";
    cin >> j;

    cout << "N is " << n << " and M is " << m << endl;
    cout << "i is " << i << " and j is " << j << endl;

    result = setNM(n, m, i, j);
    cout << "Result is " << result << endl;

    return 0;
}

