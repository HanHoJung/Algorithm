#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string convert(string &arr) {
	string var = "";
	stack<char> s;
	string front = "";
	int k = 0; 
	for (k = 0; k < arr.size(); k++) {
		if (arr[k] == '*' || arr[k] == '[' || arr[k] == ']' || arr[k] == '&')
			break;

		front += arr[k];
	}
	for (int i = k; i < arr.size(); i++)
		s.push(arr[i]);

	while (!s.empty()) {
		char c = s.top();
		s.pop();

		switch (c)
		{
		case '[':
			var += ']';
			break;
		case ']':
			var += '[';
			break;

		default:
			var += c;
			break;
			
		}

	}

	return var+' '+front;

}
int main(void) {
	vector<string> arr;
	string str;

	int k = 0;
	while (cin >> str) {	
		if (str[str.size() - 1] == ';') {
			str.pop_back();
			str=convert(str);
			arr.push_back(str);
			break;
		}
		else {
			if (k == 0) {
				arr.push_back(str);
			}
			else {
				str.pop_back();
				str = convert(str);
				arr.push_back(str);
			}
		}
		k++;
	}
	for (int i = 1; i < arr.size(); i++)
		cout << arr[0]+arr[i]+';' << "\n";

}