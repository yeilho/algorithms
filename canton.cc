#include <iostream>

using namespace std;

void get_term(int nth)
{
    int prev = 0, n = 1;
    int group = 1;
    int top, bottom;

    while (n < nth) {
        prev = n;
        n += ++group;
    }
    if (group % 2 == 0) {
        top = nth - prev;
        bottom = group+1 - top;
    } else {
        bottom = nth - prev;
        top = group+1 - bottom;
    }

    cout << "TERM " << nth << " IS " << top << "/" << bottom << endl;

    return;
}

int main(int argc, char *argv[])
{
    int count;

    cin >> count;
    if (count > 20)
        return 0;

    for (int i = 0; i < count; i++) {
        int input;
        cin >> input;
        if (input > 10000000)
            return 0;
        get_term(input);
    }

    return 0;
}

