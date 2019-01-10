#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> value;
bool check[16];
char a[16];


bool alphaCheck(int l) {
	int vowels=0;//모음
	int consonants=0;//자음

	for(int i = 0; i <l ; i++) {
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
			vowels++;
		else
			consonants++;

		if (vowels >= 1 && consonants >= 2)
			return true;
	}

	return false;

}

bool alphaCheck2(int l) {
	int vowels = 0;//모음
	int consonants = 0;//자음

	for (int i = 0; i < l; i++) {
		if (value[a[i]] == 'a' || value[a[i]] == 'e' || value[a[i]] == 'i' || value[a[i]] == 'o' || value[a[i]] == 'u')
			vowels++;
		else
			consonants++;

		if (vowels >= 1 && consonants >= 2)
			return true;
	}

	return false;

}



void go(int l, int c, int select, int next) {

	if (l == select && alphaCheck(l)) {
		for (int i = 0; i < l; i++) {
			cout << a[i];
		}
		cout << "\n";
		return;

	}

	if (next >= c)
		return;

	a[select] = value[next];
	go(l, c, select + 1, next + 1);
	a[select] = 0;
	go(l, c, select, next + 1);

}

void go2(int l, int c, int start, int index) {

	if (l == index && alphaCheck2(l)) {
		for (int i = 0; i < l; i++) {
			cout << value[a[i]];
		}
		cout << "\n";
		return;

	}

	for (int i = start; i < c; i++) {
		
		if (check[i] == false) {
			check[i] = true;
			a[index] = i;
			go2(l, c, i+1, index + 1);
			check[i] = false;
		}

	}

}

int main(void) {
	int l, c;
	scanf("%d %d", &l, &c);
	
	for (int i = 0; i < c; i++) {
		char c;
		cin >> c;
		value.push_back(c);
	}

	sort(value.begin(), value.end());
	
	/*go(l, c, 0, 0);*/
	go2(l, c, 0, 0);


}