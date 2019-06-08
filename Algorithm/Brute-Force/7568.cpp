#include <iostream>
#include <vector>
#define HIGH 3
#define EQUAL 2
#define LOW 1
using namespace std;

int rating[51];
struct body {
	int weight;
	int height;
	int rank;
	
};

void go(int n,vector<body> &arr) {
	for (int i = 0; i < n; i++) {
		struct body bd= arr[i];
		int w1 = bd.weight;
		int h1 = bd.height;
		int rank = bd.rank;

		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;

			struct body bd2 = arr[j];
			int w2 = bd2.weight;
			int h2 = bd2.height;
			
			if (w1 < w2 && h1 < h2) {
				rank++;
			}
		}
		rating[i]= rank;
	}

}

int main(void) {
	int n;
	cin >> n;
	vector<body> arr;
	for (int i = 0; i < n; i++) {
		int weight;
		int height;
		cin >> weight >> height;
		struct body bd;
		bd.weight = weight;
		bd.height = height;
		bd.rank = 1;
		arr.push_back(bd);
	}
	go(n, arr);
	for (int i = 0; i < n; i++)
		cout << rating[i] << " ";

	cout << "\n";

}