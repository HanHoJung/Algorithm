#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char MAP[6][3][3];
char color[6] = { 'w','y','r','o','g','b' };
vector<string> id = { "위","아래","앞","뒤","왼쪽","오른쪽" };

void init() {
	for (int k = 0; k < 6; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				MAP[k][i][j] = color[k];
			}
		}
	}
}
void copy(char temp[][3][3]) {

	for (int k = 0; k < 6; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp[k][i][j] = MAP[k][i][j];
			}
		}
	}
}

void circle(int k) {
	char temp[6][3][3];
	copy(temp);
	for (int i = 0; i < 3; i++) {
		char color = temp[k][0][2 - i];
		MAP[k][2 - i][2] = color;

	}

	for (int i = 0; i < 3; i++) {
		char color = temp[k][2 - i][2];
		MAP[k][2][i] = color;

	}

	for (int i = 0; i < 3; i++) {
		char color = temp[k][2][i];
		MAP[k][i][0] = color;
	}

	for (int i = 0; i < 3; i++) {
		char color = temp[k][i][0];
		MAP[k][0][2-i] = color;
	}


}
void recircle(int k) {
	char temp[6][3][3];
	copy(temp);
	for (int i = 0; i < 3; i++) {
		char color = temp[k][0][i];
		MAP[k][2 - i][0] = color;

	}

	for (int i = 0; i < 3; i++) {
		char color = temp[k][2 - i][0];
		MAP[k][2][2-i] = color;

	}

	for (int i = 0; i < 3; i++) {
		char color = temp[k][2][2 - i];
		MAP[k][i][2] = color;
	}

	for (int i = 0; i < 3; i++) {
		char color = temp[k][i][2];
		MAP[k][0][i] = color;
	}

}

void side(vector<int> select, vector<pair<int,int>> &f1, vector<pair<int, int>> &f2, vector<pair<int, int>> &f3, vector<pair<int, int>> &f4) {
	char temp[6][3][3];
	copy(temp);

	for (int i = 0; i < 3; i++) {//f1=>f2
		int k1 = select[0];
		int k2 = select[1];
		int s = f1[i].first;
		int e = f1[i].second;
		char color = temp[k1][s][e];
		s = f2[i].first;
		e = f2[i].second;
		MAP[k2][s][e] = color;
	}


	for (int i = 0; i < 3; i++) {//f2=>f3
		int k1 = select[1];
		int k2 = select[2];
		int s = f2[i].first;
		int e = f2[i].second;
		char color = temp[k1][s][e];
		s = f3[i].first;
		e = f3[i].second;
		MAP[k2][s][e] = color;
	}


	for (int i = 0; i < 3; i++) {//f3=>f4
		int k1 = select[2];
		int k2 = select[3];
		int s = f3[i].first;
		int e = f3[i].second;
		char color = temp[k1][s][e];
		s = f4[i].first;
		e = f4[i].second;
		MAP[k2][s][e] = color;
	}

	for (int i = 0; i < 3; i++) {//f4=>f1
		int k1 = select[3];
		int k2 = select[0];
		int s = f4[i].first;
		int e = f4[i].second;
		char color = temp[k1][s][e];
		s = f1[i].first;
		e = f1[i].second;
		MAP[k2][s][e] = color;
	}

}

void UP(char dir) {
	
	if (dir == '+') {
		vector<pair<int, int>> f1 = { make_pair(0,0),make_pair(0,1),make_pair(0,2)};
		vector<pair<int, int>> f2 = { make_pair(0,0),make_pair(0,1),make_pair(0,2) };
		vector<pair<int, int>> f3 = { make_pair(0,0),make_pair(0,1),make_pair(0,2) };
		vector<pair<int, int>> f4 = { make_pair(0,0),make_pair(0,1),make_pair(0,2) };

		side({3,5,2,4}, f1, f2, f3, f4);
		circle(0);
		
	}
	else {
		vector<pair<int, int>> f1 = { make_pair(0,2),make_pair(0,1),make_pair(0,0) };
		vector<pair<int, int>> f2 = { make_pair(0,2),make_pair(0,1),make_pair(0,0) };
		vector<pair<int, int>> f3 = { make_pair(0,2),make_pair(0,1),make_pair(0,0) };
		vector<pair<int, int>> f4 = { make_pair(0,2),make_pair(0,1),make_pair(0,0) };

		side({ 3,4,2,5 }, f1, f2, f3, f4);
		recircle(0);
		
	}
}

void DOWN(char dir) {

	if (dir == '+') {
		vector<pair<int, int>> f1 = { make_pair(2,2),make_pair(2,1),make_pair(2,0) };
		vector<pair<int, int>> f2 = { make_pair(2,2),make_pair(2,1),make_pair(2,0) };
		vector<pair<int, int>> f3 = { make_pair(2,2),make_pair(2,1),make_pair(2,0) };
		vector<pair<int, int>> f4 = { make_pair(2,2),make_pair(2,1),make_pair(2,0) };

		side({ 3,4,2,5 }, f1, f2, f3, f4);

	
		
		circle(1);
	

	}
	else {
		vector<pair<int, int>> f1 = { make_pair(2,0),make_pair(2,1),make_pair(2,2) };
		vector<pair<int, int>> f2 = { make_pair(2,0),make_pair(2,1),make_pair(2,2) };
		vector<pair<int, int>> f3 = { make_pair(2,0),make_pair(2,1),make_pair(2,2) };
		vector<pair<int, int>> f4 = { make_pair(2,0),make_pair(2,1),make_pair(2,2) };

		side({ 3,5,2,4 }, f1, f2, f3, f4);
		
		recircle(1);
	}
}


void RIGHT(char dir) {

	if (dir == '+') {
		vector<pair<int, int>> f1 = { make_pair(0,2),make_pair(1,2),make_pair(2,2) };
		vector<pair<int, int>> f2 = { make_pair(2,0),make_pair(1,0),make_pair(0,0) };
		vector<pair<int, int>> f3 = { make_pair(2,0),make_pair(1,0),make_pair(0,0) };
		vector<pair<int, int>> f4 = { make_pair(0,2),make_pair(1,2),make_pair(2,2) };
		side({ 0,3,1,2 }, f1, f2, f3, f4);
		circle(5);
		
		
	}
	else {
		vector<pair<int, int>> f1 = { make_pair(2,2),make_pair(1,2),make_pair(0,2) };
		vector<pair<int, int>> f2 = { make_pair(2,2),make_pair(1,2),make_pair(0,2) };
		vector<pair<int, int>> f3 = { make_pair(0,0),make_pair(1,0),make_pair(2,0) };
		vector<pair<int, int>> f4 = { make_pair(0,0),make_pair(1,0),make_pair(2,0) };
		side({ 0,2,1,3 }, f1, f2, f3, f4);
	
		recircle(5);

	}
}

void LEFT(char dir) {

	if (dir == '+') {
		vector<pair<int, int>> f1 = { make_pair(2,0),make_pair(1,0),make_pair(0,0) };
		vector<pair<int, int>> f2 = { make_pair(2,0),make_pair(1,0),make_pair(0,0) };
		vector<pair<int, int>> f3 = { make_pair(0,2),make_pair(1,2),make_pair(2,2) };
		vector<pair<int, int>> f4 = { make_pair(0,2),make_pair(1,2),make_pair(2,2) };
		side({ 0,2,1,3 }, f1, f2, f3, f4);
		circle(4);
		

	}
	else {
		vector<pair<int, int>> f1 = { make_pair(0,0),make_pair(1,0),make_pair(2,0) };
		vector<pair<int, int>> f2 = { make_pair(2,2),make_pair(1,2),make_pair(0,2) };
		vector<pair<int, int>> f3 = { make_pair(2,2),make_pair(1,2),make_pair(0,2) };
		vector<pair<int, int>> f4 = { make_pair(0,0),make_pair(1,0),make_pair(2,0) };
		side({ 0,3,1,2 }, f1, f2, f3, f4);
		
		recircle(4);

	}
}

void FRONT(char dir) {

	if (dir == '+') {
		vector<pair<int, int>> f1 = { make_pair(2,2),make_pair(2,1),make_pair(2,0) };
		vector<pair<int, int>> f2 = { make_pair(2,0),make_pair(1,0),make_pair(0,0) };
		vector<pair<int, int>> f3 = { make_pair(2,2),make_pair(2,1),make_pair(2,0) };
		vector<pair<int, int>> f4 = { make_pair(0,2),make_pair(1,2),make_pair(2,2) };
		side({ 0,5,1,4 }, f1, f2, f3, f4);
		circle(2);


	}
	else {
		vector<pair<int, int>> f1 = { make_pair(2,0),make_pair(2,1),make_pair(2,2) };
		vector<pair<int, int>> f2 = { make_pair(2,2),make_pair(1,2),make_pair(0,2) };
		vector<pair<int, int>> f3 = { make_pair(2,0),make_pair(2,1),make_pair(2,2) };
		vector<pair<int, int>> f4 = { make_pair(0,0),make_pair(1,0),make_pair(2,0) };
		side({ 0,4,1,5 }, f1, f2, f3, f4);
		recircle(2);


	}
}


void BACK(char dir) {

	if (dir == '+') {
		vector<pair<int, int>> f1 = { make_pair(0,0),make_pair(0,1),make_pair(0,2) };
		vector<pair<int, int>> f2 = { make_pair(2,0),make_pair(1,0),make_pair(0,0) };
		vector<pair<int, int>> f3 = { make_pair(0,0),make_pair(0,1),make_pair(0,2) };
		vector<pair<int, int>> f4 = { make_pair(0,2),make_pair(1,2),make_pair(2,2) };
		side({ 0,4,1,5}, f1, f2, f3, f4);
		
		circle(3);

	}
	else {
		vector<pair<int, int>> f1 = { make_pair(0,2),make_pair(0,1),make_pair(0,0) };
		vector<pair<int, int>> f2 = { make_pair(2,2),make_pair(1,2),make_pair(0,2) };
		vector<pair<int, int>> f3 = { make_pair(0,2),make_pair(0,1),make_pair(0,0) };
		vector<pair<int, int>> f4 = { make_pair(0,0),make_pair(1,0),make_pair(2,0) };
		side({ 0,5,1,4 }, f1, f2, f3, f4);
		recircle(3);


	}
}

void output() {

	for (int k = 0; k < 6; k++) {
		cout << "==================" << id[k] << "==================" << "\n";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << MAP[k][i][j] <<" ";
			}
			cout << "\n";
		}
	
		cout << "\n";
		
	}

	
}
int main(void) {

	
	int t;
	cin >> t;


	
	while (t--) {
		int n;
		cin >> n;
		getchar();
		init();
		/*output();*/
		vector<pair<char, char>> order;
		string str;
		getline(cin, str);

		for (int i = 0; i < str.size(); i++)
			if (str[i] == ' ')
				order.push_back(make_pair(str[i - 1], str[i - 2]));

		order.push_back(make_pair(str[str.size() - 1], str[str.size() - 2]));

		
		for (int k = 0; k < order.size(); k++) {
			
			switch (order[k].second)
			{
			case 'U':
				UP(order[k].first);
				break;
			case 'D':
				DOWN(order[k].first);
				break;
			case 'F':
				FRONT(order[k].first);
				break;

			case 'B':
				BACK(order[k].first);
				break;

			case 'L':
				LEFT(order[k].first);
				break;

			case 'R':
				RIGHT(order[k].first);
				break;
			}

			/*output();
			_getch();*/
		}
		for (int i = 0; i<3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << MAP[0][i][j];
			}
			cout << "\n";
		}
	}

}




