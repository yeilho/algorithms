#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 4
int ppl[] = {1, 2, 5, 10};
int side[4];    // for backtracking
int best;

void bridge(int tm, int n)
{
    if (n <= 2) {
        int max_tm = 0;
        for (int i = 0; i < N; i++) {
            if (side[i] == 0) {
                if (max_tm < ppl[i]) {
                    max_tm = ppl[i];
                }
            }
        }
        if ((tm + max_tm) < best)
            best = tm + max_tm;
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if ((side[i] == 0) && (side[j] == 0)) {
                side[i] = side[j] = 1;
                int min_val = 999, min_idx;
                int max_val = max(ppl[i], ppl[j]);

                // find min from those crossed
                for (int k = 0; k < N; k++) {
                    if (side[k] == 1) {
                        if (ppl[k] < min_val) {
                            min_val = ppl[k];
                            min_idx = k;
                        }
                    }
                }
                side[min_idx] = 0;
                int result_tm = tm + min_val + max_val;
                bridge(result_tm, n-1);
                side[i] = side[j] = 0;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < N; i++)
        side[i] = 0;
    best = 999;
    bridge(0, N);
    cout << "Time taken: " << best << endl;
    return 0;
}
