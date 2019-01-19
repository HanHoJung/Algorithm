#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> alphas;
string original;
int length;
bool check[27];
bool visit[10];
vector<int> permutation;
int maxVal;
void go(int cnt) {

	if (cnt == length) {

		int total = 0;
		for (int i = 0; i < alphas.size(); i++) {
			int sum = 0;
			for (int j = 0; j < alphas[i].size(); j++) {

				int index = original.find(alphas[i][j]);
				sum = sum * 10 + permutation[index];
			}
			total = sum + total;

		}

		maxVal = max(total, maxVal);


		return;
	}


	for (int i = 0; i < 10; i++) {
	

		if (visit[i] == false) {
			visit[i] = true;
			permutation.push_back(i);

			go(cnt + 1);

			visit[i] = false;
			permutation.pop_back();
		}
	}


}


int main(void) {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		alphas.push_back(str);

	}
	
	
	for (int i = 0; i < alphas.size(); i++) {

		for (int j = 0; j < alphas[i].size(); j++) {

			if (check[alphas[i][j]-'A'] == false) {
				check[alphas[i][j]-'A'] = true;
				original = original + alphas[i][j];
				length++;
			}
		}
	}
	sort(original.begin(), original.end());
	go(0);
	cout << maxVal;
	
}