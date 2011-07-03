// http://code.google.com/codejam/contest/dashboard?c=975485
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <vector>

using namespace std;

struct btn {
	char color;
	int number;
};

class robot {
	char color;
	int location;
	int index;
	vector<int> buttons;

public:
	robot() {}
	robot(char clr, list<struct btn>& seq) 
	{
		color = clr;
		index = -1;
		location = 1;
		typedef list<struct btn>::const_iterator iter;
		iter it = seq.begin();
		while (it != seq.end()) {
			if (it->color == color) {
				buttons.push_back(it->number);
			}
			it++;
		}
		if (seq.size() != 0) {
			index = 0;
		}
	}
	int next_button()
	{
		if (index == -1 || index >= buttons.size()) {
			return -1;
		}
		return buttons[index];
	}
	void incr_button()
	{
		index++;
	}
	void print_buttons()
	{
		cout << color << " ";
		for (vector<int>::size_type i = 0; i != buttons.size(); i++) {
			cout << buttons[i] << " ";				 
		}
		cout << endl;
	}
	void move(int next)
	{
		if (location == next || next == -1) {
			//cout << color << ": stay at button " << location << endl;
			return;
		}
		if (location > next) {
			location--;
			//cout << color << ": move to button " << location << endl;
		} else {
			location++;
			//cout << color << ": move to button " << location << endl;
		}
	}
	int action(char clr, int next)
	{
		int ret = 0;
		if (clr == color) {
			if (location == next) {
				//cout << color << ": push button " << location << endl;
				ret = 1;
			} else {
				move(next);
			}
		} else {
			move(next);
		}
		return ret;
	}
};

void create_seqeunce(list<struct btn>& sequence)
{
	int num;
	cin >> num;
	
	for (int i = 0; i < num; i++) {
		struct btn button;
		cin >> button.color >> button.number;
		sequence.push_back(button);
	}
}

void bot_trust(int case_num)
{
	int count = 0;
	int ret1, ret2;
	list<struct btn> seq;
	typedef list<struct btn>::const_iterator iter;

	create_seqeunce(seq);

	robot *orange = new robot('O', seq);
	robot *blue = new robot('B', seq);

	iter it = seq.begin();
	while (it != seq.end()) {
		ret1 = orange->action(it->color, orange->next_button());
		ret2 = blue->action(it->color, blue->next_button());

		if (ret1) {
			orange->incr_button();
			it++;
		}
		if (ret2) {
			blue->incr_button();
			it++;
		}
		count++;
	}
	cout << "Case #" << case_num << ": " << count << endl;
	delete orange;
	delete blue;
}

int main()
{
	int test_num;

	cin >> test_num;
	for (int i = 0; i < test_num; i++) {
		bot_trust(i+1);
	}
	return 0;
}