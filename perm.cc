// permutation of string

#include <iostream>
#include <list>
#include <string>
using namespace std;

void addset(char ch, list<string>& set)
{
    if (set.empty()) {
        string s(1, ch);
        set.push_back(s);
        return;
    }
    list<string> newset;
    list<string>::iterator it;
    for (it = set.begin(); it != set.end(); it++) {
        string tmpstr(*it);
        int n = tmpstr.length();
        for(int i = 0; i <= n; i++) {
            string str = tmpstr.substr(0,i) + ch + tmpstr.substr(i, tmpstr.length()-i);
            newset.push_back(str);
        }
    }
    set.clear();
    for (it = newset.begin(); it != newset.end(); it++) {
        set.push_back(*it);
    }
    newset.clear();
}

void stringperm(string str, int n, list<string>& set)
{
    if (n == 1) {
        addset(str[str.length()-n], set);
        return;
    }
    stringperm(str, n-1, set);
    addset(str[str.length()-n], set);
}

void print_sets(list<string>& set)
{
    list<string>::const_iterator it;
    for (it = set.begin(); it != set.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    string istring = "ABCD";
    list<string> set;
    stringperm(istring, istring.length(), set);
    print_sets(set);
    return 0;
}

