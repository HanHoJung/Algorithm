#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int weight[10][10];
int main(void) {
	int n;
	scanf("%d", &n);

	for (int i =1 ; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &weight[i][j]);
		}
	}

	
	vector<int> arr;
	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}

	int minval=100000000;
	do {
		/*if (arr[0] != 1)
			break;*/
		bool check = false;
		int value = 0;
		for (int i = 0; i < n; i++) {
			if (weight[arr[i]][arr[(i + 1) % n]] == 0) {
				check = true;
				break;
			}
			value = weight[arr[i]][arr[(i + 1)%n]]+value;
		}
		
		if (check == false) {
			minval = min(value, minval);
		}
		
	} while (next_permutation(arr.begin()+1, arr.end()));

	
	cout << minval << "\n";

}