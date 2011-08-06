#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


void display_input(map<string,string>& trs, map<char,char>& clr, int num, string str)
{
    cout << "Transform rule(s): " << endl;
    for (map<string,string>::iterator it = trs.begin(); 
            it != trs.end(); it++)
        cout << it->first << "," << it->second << endl;
    cout << "Clear rule(s): " << endl;
    for (map<char,char>::iterator it = clr.begin(); 
            it != clr.end(); it++)
        cout << it->first << "," << it->second << endl;
    cout << "Input string: " << str << endl;
}

void
gather_input(map<string, string> &transforms, map<char,char> &clear, int &num, string& input)
{
    string istring;
    int num_of_transforms;
    int num_of_clear;

    cin >> num_of_transforms;
    for (int i = 0; i < num_of_transforms; i ++) {
        cin >> istring;
        string left(istring,0,2);
        string rleft(istring,0,2);
        string right(istring,2,1);
        reverse(rleft.begin(), rleft.end());
        transforms.insert(pair<string,string>(left, right));
        transforms.insert(pair<string,string>(rleft, right));
    }

    cin >> num_of_clear;
    for (int i = 0; i < num_of_clear; i ++) {
        cin >> istring;
        char ch1 = istring[0];
        char ch2 = istring[1];
        clear.insert(pair<char,char>(ch2, ch1));
        clear.insert(pair<char,char>(ch1, ch2));
    }
    cin >> num;
    cin >> input;
}

void playgame(map<string,string>& trs, map<char,char>& clr, int num, string str)
{
    string output;

    for (int i = 0; i < num; i++) {
        char ch = str[i];
        output.append(str.substr(i,1));
        // transform
        if (output.length() > 1) {
            map<string,string>::iterator it;
            it = trs.find(output.substr(output.length()-2,2));
            if (it != trs.end()) {
                output.replace(output.length()-2, 2, it->second);
            }
        }
        // clear
        if (output.length() > 1) {
            map<char,char>::iterator it;
            char ch = output[output.length()-1];
            it = clr.find(ch);
            if (it != clr.end()) {
                size_t pos = output.find(it->second);
                if (pos != string::npos &&
                    pos != output.length()-1) {
                    output.erase();
                }
            }
        }
    }
    cout << str << " ";
    cout << "[";
    for (int i = 0; i < output.length(); i++) {
        cout << output[i];
        if (i != output.length()-1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main(int argc, char *argv[])
{
    int num_of_inputs;
    int istring_len;
    map<string, string> transforms;
    map<char, char> clear;
    string input_str;

    cin >> num_of_inputs;
    for (int i = 0; i < num_of_inputs; i++) {
        gather_input(transforms, clear, istring_len, input_str);
        //display_input(transforms, clear, istring_len, input_str);
        cout << "Case #" << i+1 << ": ";
        playgame(transforms, clear, istring_len, input_str);
        transforms.clear();
        clear.clear();
        input_str.clear();
    }

    return 0;
}
