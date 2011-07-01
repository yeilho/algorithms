// refer to https://www.spoj.pl/problems/STPAR/
// for problem description
//
#include <iostream>
#include <stack>

using namespace std;
#define MAXCARS 1000

int main(int argc, char *argv[])
{
    int *cars;
    int done = 0;
    int num = 0, i = 0, passed;
    int no_of_trucks = 0;
    stack<int> side;

    while (!done) {
        if (!num) {
            scanf("%d", &no_of_trucks);
        } else {
            no_of_trucks = num;
        }
        if (no_of_trucks == 0 || no_of_trucks > MAXCARS) {
            return 0;
        }

        cars = new int[no_of_trucks];
        for(i = 0 ; i < no_of_trucks ; i++) {
            cin >> cars[i];
        }
        cin >> num;
        if (num == 0) {
            done = 1;
        }

        i = 0;
        passed = 0;
        while (i < no_of_trucks) {
            if (passed+1 == cars[i]) {
                passed++;
            } else {
                side.push(cars[i]);
            }
            i++;

            while ((!side.empty()) && (side.top() == passed+1)) {
                    side.pop();
                    passed++;
            }
        }
        delete(cars);

        if (passed == no_of_trucks) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}

